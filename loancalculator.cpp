#include <cmath>
#include <QDebug>

#include "loancalculator.h"

void LoanCalculator::add_simulation(Simulation* simulation) {

    m_simulation.append(simulation);
}

void LoanCalculator::set_parameters(double loan_amount, double interest_rate, unsigned int term_month) {

    m_loan_amount = loan_amount;
    m_interest_rate = interest_rate;
    m_term_month = term_month;

}

void LoanCalculator::calculate(bool with_simulation) {

    double accum = calc_accum(m_term_month);
    if (accum > 0) {
        m_payment = m_loan_amount/accum;
    } else {
        m_payment = 0;
    }

    m_schedule.clear();
    m_total_interest = 0;

    double balance = m_loan_amount;
    for (unsigned int i=1; i<=m_term_month; i++) {

        Schedule schedule;
        schedule.seq = i;
        schedule.interest = balance * m_interest_rate/12.0;
        schedule.principal = m_payment - schedule.interest;
        schedule.ending_balance = balance - schedule.principal;

        if (with_simulation) {
            Simulation* sim;
            foreach (sim, m_simulation) {
                sim->apply(schedule);
            }

            // re-calculate ending_balance
            schedule.ending_balance = balance - schedule.principal;
            if (schedule.ending_balance < 0) {
                schedule.principal -= -schedule.ending_balance;
                schedule.ending_balance = 0;
            }
        }

        balance = schedule.ending_balance;

        m_total_interest += schedule.principal + schedule.interest;
        m_schedule.append(schedule);

        if (balance < 0.01) {
            break;
        }
    }
}

double LoanCalculator::calc_accum(unsigned int term) {

    double acc = 0;
    for (int i=1; i<=(int)term; i++) {
        acc += std::pow(1.+m_interest_rate/12.0, -i);
    }
    return acc;
}

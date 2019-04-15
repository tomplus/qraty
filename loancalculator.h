#ifndef LOANCALCULATOR_H
#define LOANCALCULATOR_H

#include <QVector>

struct Schedule {
   unsigned int seq;
   double interest;
   double principal;
   double ending_balance;
};


class LoanCalculator {

public:
    LoanCalculator() : m_loan_amount(0), m_interest_rate(0), m_term_month(0), m_payment(0) {}

    void set_parameters(double loan_amount, double interest_rate, unsigned int term_month);
    void add_simulation();

    void calculate();

    double get_payment() {return m_payment;}
    double get_total_interest() {return m_payment*m_term_month;}
    const QVector<Schedule>& get_schedule() {return m_schedule;}

private:
    double m_loan_amount;
    double m_interest_rate;
    unsigned int m_term_month;
    QVector<Schedule> m_schedule;
    double m_payment;

    double calc_accum(unsigned int term);
};

#endif // LOANCALCULATOR_H

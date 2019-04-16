#ifndef EXCESSPAYMENT_H
#define EXCESSPAYMENT_H

#include "loancalculator.h"

class ExcessPayment : public Simulation {

public:
    ExcessPayment() : m_payment(0), m_terms(0) {};
    void set_parameters(double payment, int terms) {m_payment = payment; m_terms = terms;}
    void apply(Schedule& sched);

private:
    double m_payment;
    int m_terms;

};

#endif // EXCESSPAYMENT_H

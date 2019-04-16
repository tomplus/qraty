#include "excesspayment.h"

void ExcessPayment::apply(Schedule& sched) {

    if (m_terms < 0) {
        return;
    }

    if (m_terms > 0 and m_terms < sched.seq) {
        return;
    }

    sched.principal = m_payment - sched.interest;
}

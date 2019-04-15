#include "test_loancalculator.h"
#include "loancalculator.h"
#include <cmath>

inline void CompareCurrency(double actual, double expected, double accepted_diff=0.01) {
    QVERIFY(actual-expected <= accepted_diff);
}

void TestLoanCalculator::should_return_zero_if_not_inited() {

    LoanCalculator lc;
    QCOMPARE(lc.get_payment(), 0.);

}

void TestLoanCalculator::should_return_valid_payment() {

    LoanCalculator lc;
    lc.set_parameters(1000.00, 0.02, 4);
    lc.calculate();
    CompareCurrency(lc.get_payment(), 251.04);
    CompareCurrency(lc.get_total_interest(), 1004.17);

    const QVector<Schedule> schedule = lc.get_schedule();

    CompareCurrency(schedule.size(), 4);
    CompareCurrency(schedule[0].seq, 1);
    CompareCurrency(schedule[0].interest, 1.67);
    CompareCurrency(schedule[0].principal, 249.37);
    CompareCurrency(schedule[1].seq, 2);
    CompareCurrency(schedule[1].interest, 1.25);
    CompareCurrency(schedule[1].principal, 249.79);
    CompareCurrency(schedule[2].seq, 3);
    CompareCurrency(schedule[2].interest, 0.83);
    CompareCurrency(schedule[2].principal, 250.21);
    CompareCurrency(schedule[3].seq, 4);
    CompareCurrency(schedule[3].interest, 0.42);
    CompareCurrency(schedule[3].principal, 250.63);
}

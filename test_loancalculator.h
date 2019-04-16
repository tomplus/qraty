#ifndef TESTLOANCALCULATOR_H
#define TESTLOANCALCULATOR_H

#include <QObject>
#include <QtTest/QtTest>

class TestLoanCalculator : public QObject
{
    Q_OBJECT
public:
    explicit TestLoanCalculator(QObject *parent = 0) : QObject(parent) {};

private slots:
    void should_return_zero_if_not_inited();
    void should_return_valid_payment();
    void should_apply_simulation();

};

#endif // TESTLOANCALCULATOR_H

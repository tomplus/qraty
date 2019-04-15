#ifndef TESTLOANCALCULATOR_H
#define TESTLOANCALCULATOR_H

#include <QObject>
#include <QtTest/QtTest>

class TestLoanCalculator : public QObject
{
    Q_OBJECT
public:
    explicit TestLoanCalculator(QObject *parent = 0) {};

private slots:
    void should_return_zero_if_not_inited();
    void should_return_valid_payment();

};

#endif // TESTLOANCALCULATOR_H

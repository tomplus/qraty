#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loancalculator.h"
#include "excesspayment.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update_gui();
    void on_pushButtonClone_clicked();

private:
    Ui::MainWindow *ui;
    LoanCalculator calc;
    ExcessPayment excess_payment;
};

#endif // MAINWINDOW_H

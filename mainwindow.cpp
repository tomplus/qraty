#include <cmath>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_gui();

    connect(ui->doubleSpinBoxLoanAmount, SIGNAL(valueChanged(double)), this, SLOT(update_gui()));
    connect(ui->doubleSpinBoxInterestRate, SIGNAL(valueChanged(double)), this, SLOT(update_gui()));
    connect(ui->spinBoxTerm, SIGNAL(valueChanged(int)), this, SLOT(update_gui()));
    connect(ui->doubleSpinBoxOverpay, SIGNAL(valueChanged(double)), this, SLOT(update_gui()));
    connect(ui->spinBoxOverpayCount, SIGNAL(valueChanged(int)), this, SLOT(update_gui()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_gui()
{

    calc.set_parameters(ui->doubleSpinBoxLoanAmount->value(),
                        ui->doubleSpinBoxInterestRate->value(),
                        ui->spinBoxTerm->value());

    calc.calculate();

    ui->doubleSpinBoxPayment->setValue(calc.get_payment());
    ui->doubleSpinBoxInterest->setValue(calc.get_total_interest()-ui->doubleSpinBoxLoanAmount->value());

    const QVector<Schedule> scheds = calc.get_schedule();
    ui->tableWidget->setRowCount(scheds.size());

    Schedule sched;
    foreach (sched, scheds) {
        QTableWidgetItem * item = new QTableWidgetItem(QString("%1").arg(sched.interest, 0, 'f', 2));
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tableWidget->setItem(sched.seq-1, 0, item);

        item = new QTableWidgetItem(QString("%1").arg(sched.principal, 0, 'f', 2));
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tableWidget->setItem(sched.seq-1, 1, item);

        item = new QTableWidgetItem(QString("%1").arg(sched.ending_balance, 0, 'f', 2));
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tableWidget->setItem(sched.seq-1, 2, item);
    }

}

void MainWindow::on_pushButtonClone_clicked()
{
    MainWindow *win = new MainWindow();
    win->show();
}

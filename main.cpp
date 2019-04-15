#include <QApplication>
#include <QCommandLineParser>

#include "mainwindow.h"
#include "test_loancalculator.h"

int run_tests() {
    int status = 0;
    TestLoanCalculator t_loan_calculator;
    status |= QTest::qExec(&t_loan_calculator);
    return status;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCommandLineParser parser;
    QCommandLineOption testOption(QStringList() << "t" << "test", "Run unit tests");
    parser.addOption(testOption);

    parser.process(app);
    if (parser.isSet(testOption)) {
        return run_tests();
    }


    MainWindow wnd;
    wnd.show();
    return app.exec();
}

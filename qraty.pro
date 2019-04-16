#-------------------------------------------------
#
# Project created by QtCreator 2019-04-01T22:55:17
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qraty
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        loancalculator.cpp \
        excesspayment.cpp \
        test_loancalculator.cpp

HEADERS  += mainwindow.h \
        loancalculator.h \
        excesspayment.h \
        test_loancalculator.h

FORMS    += mainwindow.ui

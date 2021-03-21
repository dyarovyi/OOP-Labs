/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *startButton;
    QSpinBox *spinLevel;
    QLabel *levelLabel;
    QLabel *timeLabel;
    QLabel *attemptsLabel;
    QLabel *attemptsCounter;
    QLabel *timer;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 500);
        MainWindow->setMinimumSize(QSize(500, 500));
        MainWindow->setMaximumSize(QSize(500, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 500, 350));
        tableWidget->setRowCount(8);
        tableWidget->setColumnCount(8);
        tableWidget->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        tableWidget->verticalHeader()->setMinimumSectionSize(40);
        tableWidget->verticalHeader()->setDefaultSectionSize(40);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(10, 400, 151, 31));
        QFont font;
        font.setPointSize(16);
        startButton->setFont(font);
        spinLevel = new QSpinBox(centralwidget);
        spinLevel->setObjectName(QString::fromUtf8("spinLevel"));
        spinLevel->setGeometry(QRect(120, 360, 44, 28));
        spinLevel->setMinimum(1);
        spinLevel->setMaximum(8);
        levelLabel = new QLabel(centralwidget);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));
        levelLabel->setGeometry(QRect(10, 360, 101, 31));
        levelLabel->setFont(font);
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(340, 360, 81, 31));
        timeLabel->setFont(font);
        attemptsLabel = new QLabel(centralwidget);
        attemptsLabel->setObjectName(QString::fromUtf8("attemptsLabel"));
        attemptsLabel->setGeometry(QRect(310, 400, 111, 31));
        attemptsLabel->setFont(font);
        attemptsCounter = new QLabel(centralwidget);
        attemptsCounter->setObjectName(QString::fromUtf8("attemptsCounter"));
        attemptsCounter->setGeometry(QRect(420, 400, 31, 31));
        attemptsCounter->setFont(font);
        timer = new QLabel(centralwidget);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(420, 360, 31, 31));
        timer->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START!", nullptr));
        levelLabel->setText(QCoreApplication::translate("MainWindow", "Choose level", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "Time left:", nullptr));
        attemptsLabel->setText(QCoreApplication::translate("MainWindow", "Attempts left:", nullptr));
        attemptsCounter->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        timer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

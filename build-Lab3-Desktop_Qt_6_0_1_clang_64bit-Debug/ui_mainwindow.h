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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHello;
    QAction *actionMore;
    QAction *actionCool;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_write;
    QPushButton *pushButton_read;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuMore;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(396, 205);
        actionHello = new QAction(MainWindow);
        actionHello->setObjectName(QString::fromUtf8("actionHello"));
        actionMore = new QAction(MainWindow);
        actionMore->setObjectName(QString::fromUtf8("actionMore"));
        actionCool = new QAction(MainWindow);
        actionCool->setObjectName(QString::fromUtf8("actionCool"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_write = new QPushButton(centralwidget);
        pushButton_write->setObjectName(QString::fromUtf8("pushButton_write"));

        horizontalLayout->addWidget(pushButton_write);

        pushButton_read = new QPushButton(centralwidget);
        pushButton_read->setObjectName(QString::fromUtf8("pushButton_read"));

        horizontalLayout->addWidget(pushButton_read);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 396, 21));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuMore = new QMenu(menubar);
        menuMore->setObjectName(QString::fromUtf8("menuMore"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuMore->menuAction());
        menuMenu->addAction(actionHello);
        menuMenu->addAction(actionMore);
        menuMore->addAction(actionCool);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHello->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionMore->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionCool->setText(QCoreApplication::translate("MainWindow", "Cool", nullptr));
        pushButton_write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        pushButton_read->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuMore->setTitle(QCoreApplication::translate("MainWindow", "More", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

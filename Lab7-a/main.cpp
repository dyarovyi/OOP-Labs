#include "mainwindow.h"

#include <QApplication>


int List::countLists = 0;
bool List::outputLeftToRight = true;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

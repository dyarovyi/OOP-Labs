#include "mainwindow.h"

#include <QApplication>

//----------------------------------------------------------------------------------
double Package::tarriff = 100;
double Value::tarriff = 120;
double Transfer::tarriff = 10;


//----------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include "sendings.hpp"


//----------------------------------------------------------------------------------
namespace Ui
{
    class MainWindow;
}


//----------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double calculatePackage();
    double calculateValue();
    double calculateTransfer();

private slots:
    void on_radioBanderol_clicked();
    void on_radioPricy_clicked();
    void on_radioOnline_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


//----------------------------------------------------------------------------------
#endif // MAINWINDOW_H

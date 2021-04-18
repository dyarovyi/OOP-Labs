#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <fstream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

//--------------------------------------------------------------------------------
class Drib
{
    int numerator;
    int denominator;

public:
    Drib(int newNumerator, int newDenominator);
    Drib(int newNumerator);
    Drib(void);
    ~Drib();

    static int counter;
    static void getCounter(void);

    void setDrib(int, int);
    void displayDrib(void);

    int getNumerator(void);
    int getDenominator(void);
    void setNumerator(int);
    void setDenominator(int);

    int greatestCommonDivisor(int newNumerator, int newDenominator);
    void reduceFraction(void);

    void readFromForm(Drib);
    void writeToForm(Drib);

    void sum(Drib dribB);
    void difference(Drib dribB);
    void product(Drib dribB);

    void sum(int);
    void difference(int);
    void product(int);

    void operator + (Drib B);
    void operator - (Drib B);
    void operator * (Drib B);
    void operator / (Drib B);
    void operator ^ (int p);

    friend void operator << (Ui::MainWindow*, Drib &fraction);
    friend void operator >> (Ui::MainWindow*, Drib &fraction);

    friend bool operator > (Drib A, Drib B);
    friend bool operator < (Drib A, Drib B);
    friend bool operator == (Drib A, Drib B);

};


//--------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Drib readFromFormA(void);
    Drib readFromFormB(void);
    void writeToForm(Drib);

private slots:
    void on_buttonSum_clicked();
    void on_buttonDifference_clicked();
    void on_buttonProduct_clicked();
    void on_buttonDivision_clicked();
    void on_buttonPower_clicked();
    void on_buttonReduce_clicked();
    void on_buttonRelation_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

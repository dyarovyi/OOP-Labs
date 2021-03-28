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
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonSum_clicked();

    void on_buttonDifference_clicked();

    void on_buttonProduct_clicked();

    void on_buttonDivision_clicked();

    void on_buttonPower_clicked();

    void on_buttonReduce_clicked();

private:
    Ui::MainWindow *ui;
};


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

    void setDrib(void);
    void displayDrib(void);

    int getNumerator(void);
    void setNumerator(void);
    int getDenominator(void);
    void setDenominator(void);

    void sum(Drib dribB);
    void difference(Drib dribB);
    void product(Drib dribB);
    void division(Drib dribB);
    void power(int);

    int greatestCommonDivisor(int newNumerator, int newDenominator);
    void reduceFraction(void);

    void readFraction();
    void writeFraction();
};


//--------------------------------------------------------------------------------
/*
    Клас Drib – звичайний дріб. Клас повинен містити функції-члени, які реалізовують:
    а)Додавання
    б)Віднімання
    в)Множення
    г)Ділення
    ґ)Скорочення дробу
    д)Задавання значень полів
    е)Зчитування (отримання значень полів)
    є)Піднесення до степеня
    ж)Введення дробу з форми
    з)Виведення дробу на форму.
 */

#endif // MAINWINDOW_H

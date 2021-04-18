#include "mainwindow.h"
#include "ui_mainwindow.h"


// Конструктор вікна
//--------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


// Деструктор вікна
//--------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}


// Конструктор за двома значеннями
//--------------------------------------------------------------------------------
Drib::Drib(int newNumerator, int newDenominator)
{
    numerator = newNumerator;
    denominator = newDenominator;
    counter++;
}


// Конструктор за одним значенням
//--------------------------------------------------------------------------------
Drib::Drib(int newNumerator)
{
    numerator = newNumerator;
    denominator = 1;
    counter++;
}


// Конструктор за замовчуванням
//--------------------------------------------------------------------------------
Drib::Drib(void)
{
    numerator = 1;
    denominator = 1;
    counter++;
}


// Скільки об'єктів створено
//--------------------------------------------------------------------------------
void getCounter(void)
{
    cout << Drib::counter << endl;
}


// Деструктор
//--------------------------------------------------------------------------------
Drib::~Drib(void)
{

}


// Задання значень чисельника та знаменника
//--------------------------------------------------------------------------------
void Drib::setDrib(int n, int d)
{
    setNumerator(n);
    setDenominator(d);
}


// Задання значення чисельника
//--------------------------------------------------------------------------------
void Drib::setNumerator(int n)
{
    numerator = n;
}


// Задання значення знаменника
//--------------------------------------------------------------------------------
void Drib::setDenominator(int d)
{
    denominator = d;
}


// Взяття чисельника з дробу
//--------------------------------------------------------------------------------
int Drib::getNumerator()
{
    return numerator;
}


// Взяття знаменника з дробу
//--------------------------------------------------------------------------------
int Drib::getDenominator()
{
    return denominator;
}


// Виведення дробу в консоль
//--------------------------------------------------------------------------------
void Drib::displayDrib()
{
    cout << numerator << "/" << denominator << endl;
}


// Перевантаження +
//--------------------------------------------------------------------------------
void Drib::operator + (Drib B)
{
    int newNumerator = numerator * B.denominator + B.numerator * denominator;
    int newDenominator = denominator * B.denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Перевантаження -
//--------------------------------------------------------------------------------
void Drib::operator - (Drib B)
{
    int newNumerator = numerator * B.denominator - B.numerator * denominator;
    int newDenominator = denominator * B.denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}

// Перевантаження *
//--------------------------------------------------------------------------------
void Drib::operator * (Drib B)
{
    int newNumerator = numerator * B.numerator;
    int newDenominator = denominator * B.denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Перевантаження /
//--------------------------------------------------------------------------------
void Drib::operator / (Drib B)
{
    int newNumerator = numerator * B.denominator;
    int newDenominator = B.numerator * denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Перевантаження ^
//--------------------------------------------------------------------------------
void Drib::operator ^ (int p)
{
    int newNumerator = numerator;
    int newDenominator = denominator;

    if (p == 0)
    {
        numerator = 1;
        denominator = 1;
    }
    else
    {
        for (int i = 1; i < p; i++)
        {
            newNumerator *= numerator;
            newDenominator *= denominator;
        }

        numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
        denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
    }
}


// Знаходження найбільшого спільного дільника
//--------------------------------------------------------------------------------
int Drib::greatestCommonDivisor(int newNumerator, int newDenominator)
{
    int remainder;
    while (newDenominator != 0)
    {
        remainder = newNumerator % newDenominator;
        newNumerator = newDenominator;
        newDenominator = remainder;
    }
    return newNumerator;
}


// Скорочення дробу
//--------------------------------------------------------------------------------
void Drib::reduceFraction()
{
    int newNumerator = numerator;
    int newDenominator = denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// ОБЧИСЛЕННЯ СУМИ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonSum_clicked()
{
    ui->labelOperator->setText("+");

    Drib A = readFromFormA();
    /*Drib B = readFromFormB();
    A + B;*/

    if (ui->fractionBDenominator->toPlainText() == "")
    {
        bool ok;
        QString nText = ui->fractionBNumerator->toPlainText();
        int N = nText.toInt(&ok, 10);
        A.sum(N);
    }
    else
    {
        Drib B = readFromFormB();
        A.sum(B);
    }

    writeToForm(A);
}


// ОБЧИСЛЕННЯ РІЗНИЦІ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonDifference_clicked()
{
    ui->labelOperator->setText("-");

    Drib A = readFromFormA();
    /*Drib B = readFromFormB();
    A - B;*/

    if (ui->fractionBDenominator->toPlainText() == "")
    {
        bool ok;
        QString nText = ui->fractionBNumerator->toPlainText();
        int N = nText.toInt(&ok, 10);
        A.difference(N);
    }
    else
    {
        Drib B = readFromFormB();
        A.difference(B);
    }

    writeToForm(A);
}


// ОБЧИСЛЕННЯ ДОБУТКУ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonProduct_clicked()
{
    ui->labelOperator->setText("x");

    Drib A = readFromFormA();
    Drib B = readFromFormB();
    //A * B;

    if (ui->fractionBDenominator->toPlainText() == "")
    {
        bool ok;
        QString nText = ui->fractionBNumerator->toPlainText();
        int N = nText.toInt(&ok, 10);
        A.product(N);
    }
    else
    {
        Drib B = readFromFormB();
        A.product(B);
    }


    writeToForm(A);
}


// ОБЧИСЛЕННЯ ЧАСТКИ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonDivision_clicked()
{
    ui->labelOperator->setText("/");

    Drib A = readFromFormA();
    Drib B = readFromFormB();
    A / B;

    writeToForm(A);
}


// ПІДНЕСЕННЯ ДО СТЕПЕНЯ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonPower_clicked()
{
    bool ok;
    ui->labelOperator->setText("^");

    QString powerText = ui->fractionBNumerator->toPlainText();
    ui->fractionBDenominator->setText("Дріб ліворуч піднесено до степеня вгорі.");
    int powerNumber = powerText.toInt(&ok, 10);

    if (powerNumber < 0)
    {
        powerNumber = 1;
        ui->fractionBDenominator->setText("Введений степінь < 0. Степінь за замовчуванням = 1.");
    }

    Drib A = readFromFormA();
    A ^ powerNumber;

    writeToForm(A);
}


// СКОРОЧЕННЯ ДРОБУ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonReduce_clicked()
{
    ui->labelOperator->setText("");

    ui->fractionBNumerator->setText("Скорочееня дробу зліва.");
    ui->fractionBDenominator->setText("");

    Drib A = readFromFormA();
    A.reduceFraction();

    writeToForm(A);
}


// ЗАЛЕЖНІСТЬ > < ==
//--------------------------------------------------------------------------------
void MainWindow::on_buttonRelation_clicked()
{
    Drib A = readFromFormA();
    Drib B = readFromFormB();

    if (A < B)
    {
        ui->labelOperator->setText("<");
    }
    else if (A > B)
    {
        ui->labelOperator->setText(">");
    }
    else
    {
       ui->labelOperator->setText("==");
    }

    ui->labelResultNumerator->setText("");
    ui->labelResultDenominator->setText("");
    getCounter();
}


// Перевантаження >
//--------------------------------------------------------------------------------
bool operator > (Drib A, Drib B)
{
    int tempD = A.denominator;

    A.numerator *= B.denominator;
    A.denominator *= B.denominator;

    B.numerator *= tempD;
    B.denominator *= tempD;

    if (A.numerator > B.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Перевантаження <
//--------------------------------------------------------------------------------
bool operator < (Drib A, Drib B)
{
    int tempD = A.denominator;

    A.numerator *= B.denominator;
    A.denominator *= B.denominator;

    B.numerator *= tempD;
    B.denominator *= tempD;

    if (A.numerator < B.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Перевантаження ==
//--------------------------------------------------------------------------------
bool operator == (Drib A, Drib B)
{
    int tempD = A.denominator;

    A.numerator *= B.denominator;
    A.denominator *= B.denominator;

    B.numerator *= tempD;
    B.denominator *= tempD;

    if (A.numerator == B.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Зчитування дробу A з форми
//--------------------------------------------------------------------------------
Drib MainWindow::readFromFormA(void)
{/*
    bool ok;

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    Drib A(newNumeratorA, newDenominatorA);*/
    Drib A;
    ui >> A;
    return A;
}


// Зчитування дробу B з форми
//--------------------------------------------------------------------------------
Drib MainWindow::readFromFormB(void)
{
    bool ok;

    QString newNumeratorBText = ui->fractionBNumerator->toPlainText();
    QString newDenominatorBText = ui->fractionBDenominator->toPlainText();
    int newNumeratorB = newNumeratorBText.toInt(&ok, 10);
    int newDenominatorB = newDenominatorBText.toInt(&ok, 10);

    Drib B(newNumeratorB, newDenominatorB);
    return B;
}


// Запис дробу у форму
//--------------------------------------------------------------------------------
void MainWindow::writeToForm(Drib A)
{
    /*
    ui->labelResultNumerator->setText(QString::number(A.getNumerator()));
    ui->labelResultDenominator->setText(QString::number(A.getDenominator()));
    cout << endl << "Counter: ";
    getCounter();
    cout << endl;*/

    ui << A;
}


// Перевантаження <<
//--------------------------------------------------------------------------------
void operator << (Ui::MainWindow *ui, Drib &fraction)
{
   ui->labelResultNumerator->setText(QString::number(fraction.getNumerator()));
   ui->labelResultDenominator->setText(QString::number(fraction.getDenominator()));
}


// Перевантаження >>
//--------------------------------------------------------------------------------
void operator >> (Ui::MainWindow *ui, Drib &fraction)
{
    bool ok;

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    fraction.setDrib(newNumeratorA, newDenominatorA);
}


// Сума двох дробів
//--------------------------------------------------------------------------------
void Drib::sum(Drib fractionB)
{
    int newNumerator = numerator * fractionB.denominator + fractionB.numerator * denominator;
    int newDenominator = denominator * fractionB.denominator;
    //return Drib(newNumerator / greatestCommonDivisor(newNumerator, newDenominator), newDenominator / greatestCommonDivisor(newNumerator, newDenominator));
    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Різниця двох дробів
//--------------------------------------------------------------------------------
void Drib::difference(Drib fractionB)
{
    int newNumerator = numerator * fractionB.denominator - fractionB.numerator * denominator;
    int newDenominator = denominator * fractionB.denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Множення двох дробів
//--------------------------------------------------------------------------------
void Drib::product(Drib fractionB)
{
    int newNumerator = numerator * fractionB.numerator;
    int newDenominator = denominator * fractionB.denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Перевантаження додавання
//--------------------------------------------------------------------------------
void Drib::sum(int N)
{
    int newNumerator = numerator + N * denominator;
    int newDenominator = denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Перевантаження відномання
//--------------------------------------------------------------------------------
void Drib::difference(int N)
{
    int newNumerator = numerator - N * denominator;
    int newDenominator = denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Перевантаження множення
//--------------------------------------------------------------------------------
void Drib::product(int N)
{
    int newNumerator = numerator * N;
    int newDenominator = denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}

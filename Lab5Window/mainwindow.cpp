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
}


// Конструктор за одним значенням
//--------------------------------------------------------------------------------
Drib::Drib(int newNumerator)
{
    numerator = newNumerator;
    denominator = 1;
}


// Конструктор за замовчуванням
//--------------------------------------------------------------------------------
Drib::Drib(void)
{
    numerator = 1;
    denominator = 1;
}


// Деструктор
//--------------------------------------------------------------------------------
Drib::~Drib(void)
{

}


// Задання значень чисельника та знаменника
//--------------------------------------------------------------------------------
void Drib::setDrib()
{
    setNumerator();
    setDenominator();
}


// Задання значення чисельника
//--------------------------------------------------------------------------------
void Drib::setNumerator()
{
    int newNumerator;
    cout << "Enter value for numerator: ";
    cin >> newNumerator;
    numerator = newNumerator;
}


// Задання значення знаменника
//--------------------------------------------------------------------------------
void Drib::setDenominator()
{
    int newDenominator = 0;

    do
    {
        cout << "Enter value for deniminator: ";
        cin >> newDenominator;

        if (newDenominator == 0)
        {
            cout << "Denominator must not be equal to 0!" << endl;
            cout << "Try again." << endl;
        }
    } while (newDenominator == 0);

    denominator = newDenominator;
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


// Сума двох дробів
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


// Ділення двох дробів
//--------------------------------------------------------------------------------
void Drib::division(Drib fractionB)
{
    int newNumerator = numerator * fractionB.denominator;
    int newDenominator = fractionB.numerator * denominator;

    numerator = newNumerator / greatestCommonDivisor(newNumerator, newDenominator);
    denominator = newDenominator / greatestCommonDivisor(newNumerator, newDenominator);
}


// Піднесення дробу до степеня
//--------------------------------------------------------------------------------
void Drib::power(int p)
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


// Зчитування дробу з форми
//--------------------------------------------------------------------------------
void Drib::readFraction()
{
    ifstream file;
    file.open("read.txt");

    file >> numerator;
    file.ignore(1);
    file >> denominator;

    file.close();
}


// Запис дробу у форму
//--------------------------------------------------------------------------------
void Drib::writeFraction()
{
    ofstream file;
    file.open("write.txt");

    file << numerator << "/" << denominator << endl;

    file.close();
}


// ОБЧИСЛЕННЯ СУМИ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonSum_clicked()
{
    bool ok;
    ui->labelOperator->setText("+");

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    QString newNumeratorBText = ui->fractionBNumerator->toPlainText();
    QString newDenominatorBText = ui->fractionBDenominator->toPlainText();
    int newNumeratorB = newNumeratorBText.toInt(&ok, 10);
    int newDenominatorB = newDenominatorBText.toInt(&ok, 10);

    Drib A(newNumeratorA, newDenominatorA);
    Drib B(newNumeratorB, newDenominatorB);
    A.sum(B);

    ui->labelResultNumerator->setText(QString::number(A.getNumerator()));
    ui->labelResultDenominator->setText(QString::number(A.getDenominator()));
}


// ОБЧИСЛЕННЯ РІЗНИЦІ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonDifference_clicked()
{
    bool ok;
    ui->labelOperator->setText("-");

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    QString newNumeratorBText = ui->fractionBNumerator->toPlainText();
    QString newDenominatorBText = ui->fractionBDenominator->toPlainText();
    int newNumeratorB = newNumeratorBText.toInt(&ok, 10);
    int newDenominatorB = newDenominatorBText.toInt(&ok, 10);

    Drib A(newNumeratorA, newDenominatorA);
    Drib B(newNumeratorB, newDenominatorB);
    A.difference(B);

    ui->labelResultNumerator->setText(QString::number(A.getNumerator()));
    ui->labelResultDenominator->setText(QString::number(A.getDenominator()));
}


// ОБЧИСЛЕННЯ ДОБУТКУ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonProduct_clicked()
{
    bool ok;
    ui->labelOperator->setText("x");

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    QString newNumeratorBText = ui->fractionBNumerator->toPlainText();
    QString newDenominatorBText = ui->fractionBDenominator->toPlainText();
    int newNumeratorB = newNumeratorBText.toInt(&ok, 10);
    int newDenominatorB = newDenominatorBText.toInt(&ok, 10);

    Drib A(newNumeratorA, newDenominatorA);
    Drib B(newNumeratorB, newDenominatorB);
    A.product(B);

    ui->labelResultNumerator->setText(QString::number(A.getNumerator()));
    ui->labelResultDenominator->setText(QString::number(A.getDenominator()));
}


// ОБЧИСЛЕННЯ ЧАСТКИ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonDivision_clicked()
{
    bool ok;
    ui->labelOperator->setText("/");

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    QString newNumeratorBText = ui->fractionBNumerator->toPlainText();
    QString newDenominatorBText = ui->fractionBDenominator->toPlainText();
    int newNumeratorB = newNumeratorBText.toInt(&ok, 10);
    int newDenominatorB = newDenominatorBText.toInt(&ok, 10);

    Drib A(newNumeratorA, newDenominatorA);
    Drib B(newNumeratorB, newDenominatorB);
    A.division(B);

    ui->labelResultNumerator->setText(QString::number(A.getNumerator()));
    ui->labelResultDenominator->setText(QString::number(A.getDenominator()));
}


// ПІДНЕСЕННЯ ДО СТЕПЕНЯ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonPower_clicked()
{
    bool ok;
    ui->labelOperator->setText("^");

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    QString powerText = ui->fractionBNumerator->toPlainText();
    ui->fractionBDenominator->setText("Дріб ліворуч піднесено до степеня вгорі.");
    int powerNumber = powerText.toInt(&ok, 10);

    if (powerNumber < 0)
    {
        powerNumber = 1;
        ui->fractionBDenominator->setText("Введений степінь < 0. Степінь за замовчуванням = 1.");
    }

    Drib A(newNumeratorA, newDenominatorA);
    A.power(powerNumber);

    ui->labelResultNumerator->setText(QString::number(A.getNumerator()));
    ui->labelResultDenominator->setText(QString::number(A.getDenominator()));
}


// СКОРОЧЕННЯ ДРОБУ
//--------------------------------------------------------------------------------
void MainWindow::on_buttonReduce_clicked()
{
    bool ok;
    ui->labelOperator->setText("");

    QString newNumeratorAText = ui->fractionANumerator->toPlainText();
    QString newDenominatorAText = ui->fractionADenominator->toPlainText();
    int newNumeratorA = newNumeratorAText.toInt(&ok, 10);
    int newDenominatorA = newDenominatorAText.toInt(&ok, 10);

    ui->fractionBNumerator->setText("Скорочееня дробу зліва.");
    ui->fractionBDenominator->setText("");

    Drib A(newNumeratorA, newDenominatorA);
    A.reduceFraction();

    ui->labelResultNumerator->setText(QString::number(A.getNumerator()));
    ui->labelResultDenominator->setText(QString::number(A.getDenominator()));
}

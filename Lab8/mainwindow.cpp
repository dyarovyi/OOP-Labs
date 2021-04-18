#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("/Users/daniilyarovyy/Desktop/ООП/Лаби/Lab8/2.png");
    ui->label->setPixmap(pix);
}


MainWindow::~MainWindow()
{
    delete ui;
}


//----------------------------------------------------------------------------------
void MainWindow::on_radioBanderol_clicked()
{
    if (ui->radioPricy->isChecked() || ui->radioOnline->isChecked())
    {
        ui->radioBanderol->setChecked(true);
        ui->radioPricy->setChecked(false);
        ui->radioOnline->setChecked(false);
    }

    ui->labelWeight->setText("Введіть вагу у КГ:");
    ui->doubleSpinBox->setEnabled(true);

    ui->labelValue->setText("");
    ui->textEditPrice->setEnabled(false);

    ui->labelCity->setText("Введіть місто відправки:");
    ui->textEditCity->setEnabled(true);
}


//----------------------------------------------------------------------------------
void MainWindow::on_radioPricy_clicked()
{
    if (ui->radioBanderol->isChecked() || ui->radioOnline->isChecked())
    {
        ui->radioBanderol->setChecked(false);
        ui->radioPricy->setChecked(true);
        ui->radioOnline->setChecked(false);
    }

    ui->labelWeight->setText("Введіть вагу у КГ:");
    ui->doubleSpinBox->setEnabled(true);

    ui->labelValue->setText("Введіть ціну у ₴:");
    ui->textEditPrice->setEnabled(true);

    ui->labelCity->setText("Введіть місто відправки:");
    ui->textEditCity->setEnabled(true);
}


//----------------------------------------------------------------------------------
void MainWindow::on_radioOnline_clicked()
{
    if (ui->radioPricy->isChecked() || ui->radioPricy->isChecked())
    {
        ui->radioBanderol->setChecked(false);
        ui->radioPricy->setChecked(false);
        ui->radioOnline->setChecked(true);
    }

    ui->labelWeight->setText("");
    ui->doubleSpinBox->setEnabled(false);

    ui->labelValue->setText("");
    ui->textEditPrice->setEnabled(false);

    ui->labelCity->setText("");
    ui->textEditCity->setEnabled(false);
}


//----------------------------------------------------------------------------------
void MainWindow::on_pushButton_clicked()
{
    fstream  file;
    file.open("/Users/daniilyarovyy/Desktop/results.txt", fstream::in | fstream::app);

    double results;
    string className;

    if (ui->radioBanderol->isChecked())
    {
        results = calculatePackage();
        className = "PACKAGE";
        ui->labelPrice->setText("₴ " + QString::number(results));
    }
    else if (ui->radioPricy->isChecked())
    {
        results = calculateValue();
        className = "VALUE";
        ui->labelPrice->setText("₴ " + QString::number(results));
    }
    else
    {
        className = "TRANSFER";
        results = calculateTransfer();
        ui->labelPrice->setText("₴ " + QString::number(results));
    }

    file << className << " ₴ " << results << endl;
    file.close();
}


//----------------------------------------------------------------------------------
double MainWindow::calculatePackage()
{
    bool ok;
    int Q = ui->spinBox->text().toInt(&ok, 10);
    double W = ui->doubleSpinBox->text().toDouble(&ok);

    string C = ui->textEditCity->toPlainText().toStdString();

    Package P(Q, W, C);

    ui->labelClass->setText(QString::fromStdString(P.print()));

    return P.calculatePrice();
}


//----------------------------------------------------------------------------------
double MainWindow::calculateValue()
{
    bool ok;
    int Q = ui->spinBox->text().toInt(&ok, 10);
    double W = ui->doubleSpinBox->text().toDouble(&ok);
    double V = ui->textEditPrice->toPlainText().toDouble(&ok);

    string C = ui->textEditCity->toPlainText().toStdString();

    Value P(Q, W, V, C);

    ui->labelClass->setText(QString::fromStdString(P.print()));

    return P.calculatePrice();
}


//----------------------------------------------------------------------------------
double MainWindow::calculateTransfer()
{
    bool ok;
    int Q = ui->spinBox->text().toInt(&ok, 10);

    Transfer T(Q);

    ui->labelClass->setText(QString::fromStdString(T.print()));

    return T.calculatePrice();
}

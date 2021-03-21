#include "mainwindow.h"
#include "ui_mainwindow.h"

double previous_number = 0;

MainWindow :: MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui :: MainWindow)
{
    ui->setupUi (this);

    connect (ui->pushButton_0, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_1, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_2, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_3, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_4, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_5, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_6, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_7, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_8, SIGNAL (released ()), this, SLOT (digits ()));
    connect (ui->pushButton_9, SIGNAL (released ()), this, SLOT (digits ()));

    connect (ui->pushButton_point, SIGNAL (released ()), this, SLOT (on_pushButton_point_clicked ()));
    connect (ui->pushButton_sign, SIGNAL (released ()), this, SLOT (on_pushButton_sign_clicked ()));

    connect (ui->pushButton_plus, SIGNAL (released ()), this, SLOT (operations ()));
    connect (ui->pushButton_minus, SIGNAL (released ()), this, SLOT (operations ()));
    connect (ui->pushButton_multiply, SIGNAL (released ()), this, SLOT (operations ()));
    connect (ui->pushButton_divide, SIGNAL (released ()), this, SLOT (operations ()));

    ui->pushButton_plus->setCheckable (true);
    ui->pushButton_minus->setCheckable (true);
    ui->pushButton_multiply->setCheckable (true);
    ui->pushButton_divide->setCheckable (true);
}


MainWindow :: ~MainWindow ()
{
    delete ui;
}


void MainWindow :: digits ()
{
    QPushButton *button = (QPushButton*) sender ();
    double output;
    QString new_output;

    if (ui->label->text ().contains ('.') && button->text () == "0")
    {
        new_output = ui->label->text () + button->text ();
    }
    else
    {
        output = (ui->label->text () + button->text ()).toDouble ();
        new_output = QString :: number (output, 'g', 15);
    }

    ui->label->setText (new_output);
}


void MainWindow :: operations ()
{
    QPushButton *button = (QPushButton*) sender ();
    previous_number = ui->label->text ().toDouble ();

    ui->label->setText ("");
    button->setChecked (true);
}


void MainWindow :: on_pushButton_clear_clicked ()
{
    ui->label->setText ("0");
    previous_number = 0;

    ui->pushButton_plus->setChecked (false);
    ui->pushButton_minus->setChecked (false);
    ui->pushButton_multiply->setChecked (false);
    ui->pushButton_divide->setChecked (false);
}


void MainWindow :: on_pushButton_point_clicked ()
{
    if (!(ui->label->text ().contains ('.')))
    {
        ui->label->setText (ui->label->text () + ".");
    }
}


void MainWindow :: on_pushButton_sign_clicked () // - не працює?
{
    double minus_one = -1.0;
    double output;
    output = (ui->label->text ().toDouble () * minus_one);
    QString new_output;
    new_output = QString :: number (output, 'g', 15);
    ui->label->setText (new_output);
}


void MainWindow :: on_pushButton_equals_clicked ()
{
    double result, current_number;
    QString new_output;

    current_number = ui->label->text ().toDouble ();

    //ui->pushButton_equals->setStyleSheet("background-color: rgb(250, 0, 0)");

    if (ui->pushButton_plus->isChecked ())
    {
        result = previous_number + current_number;
        new_output = QString :: number (result, 'g', 15);
        ui->label->setText (new_output);

        ui->pushButton_plus->setChecked (false);
    }
    else if (ui->pushButton_minus->isChecked ())
    {
        result = previous_number - current_number;
        new_output = QString :: number (result, 'g', 15);
        ui->label->setText (new_output);

        ui->pushButton_minus->setChecked (false);
    }
    else if (ui->pushButton_multiply->isChecked ())
    {
        result = previous_number * current_number;
        new_output = QString :: number (result, 'g', 15);
        ui->label->setText (new_output);

        ui->pushButton_multiply->setChecked (false);
    }
    else if (ui->pushButton_divide->isChecked ())
    {
        if (current_number == 0)
        {
            ui->label->setText ("0");
        }
        else
        {
            result = previous_number / current_number;
            new_output = QString :: number (result, 'g', 15);
            ui->label->setText (new_output);
        }

        ui->pushButton_divide->setChecked (false);
    }
}

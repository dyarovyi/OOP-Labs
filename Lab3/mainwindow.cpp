#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::MainWindow)
{
    ui->setupUi (this);
}

MainWindow::~MainWindow ()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked ()
{
    QString file_name = QFileDialog :: getOpenFileName (this, "Open a file", "/Users");
    QMessageBox :: information (this, "..", file_name);
}

void MainWindow::on_pushButton_write_clicked ()
{
    QFile file ("/User/admin/Desktop");

    if (file.open (QFile :: WriteOnly | QFile :: Text))
    {
        QMessageBox :: warning (this, "title", "File not open");
    }

    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText ();
    out << Q
}

void MainWindow::on_pushButton_read_clicked ()
{

}

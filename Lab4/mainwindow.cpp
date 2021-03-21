#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setColumnCount(8);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        for (int column = 0; column < ui->tableWidget->colorCount(); column++)
        {
            QTableWidgetItem *item = new QTableWidgetItem("0");
            ui->tableWidget->setItem(row, column, item);
        }
    }

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(1000);
}

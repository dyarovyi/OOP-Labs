#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->gridLayoutWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.pmg *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);

    QString filename = QFileDialog::getOpenFileName (this, tr ("Open Images"), "", tr ("Image Files (*.png *.jpg)"));
    if (!filename.isEmpty())
    {
        QImage image(filename);
        ui->label->setPixmap(QPixmap::fromImage(image).scaled(500, 500, Qt::KeepAspectRatio));

    }
}

void MainWindow::on_actionOpen_picture_triggered()
{
    on_pushButton_clicked();
}

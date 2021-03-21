#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = nullptr);
    ~MainWindow ();

private:
    Ui::MainWindow *ui;

private slots:
    void digits ();
    void operations ();
    void on_pushButton_clear_clicked ();
    void on_pushButton_point_clicked ();
    void on_pushButton_sign_clicked ();
    void on_pushButton_equals_clicked ();
};

#endif // MAINWINDOW_H

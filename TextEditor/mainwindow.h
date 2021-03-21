#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QTextCursor>
#include <QInputDialog>


namespace Ui
{
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();


    void on_actionBold_triggered();

    void on_actionItalics_triggered();

    void on_actionUnderline_triggered();

    void on_actionPlain_triggered();

    void on_actionPrint_triggered();

    void on_actionColor_triggered();

    void on_actionFont_triggered();

    void on_actionFind_replace_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};

#endif // MAINWINDOW_H

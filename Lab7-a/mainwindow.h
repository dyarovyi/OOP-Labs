#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QListWidget>
#include <QStringList>
#include <QStringListModel>


using namespace std;

namespace Ui
{
    class MainWindow;
}


#include <iostream>

//--------------------------------------------------------------------------------
struct Node
{
    int value;
    Node *previous;
    Node *next;
};
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
class List
{
private:
    Node *head;
    Node *tail;

    static int countLists;
    static bool outputLeftToRight;
    int countElements;

public:
    List();
    List(int);
    List(List &);
    ~List();

    int getCountElements();
    Node *getLeft(List *);
    Node *getRight(List *);

    double meanValue();
    void sortSelection();
    void sortBubble();

    static void setOutputLeftToRight(bool);

    void addNodeRight(int);
    void addNodeLeft(int);
    void deleteNodeRight();
    void deleteNodeLeft();

    void timesScalar(int);
    int getValueOfElementIndex(int);

    void operator + (int);
    void operator - (int);
    void operator ++ ();
    void operator -- ();

    void operator = (List &);

    friend void operator << (Ui::MainWindow *, List &);
    friend void operator >> (Ui::MainWindow *, List &);

    friend void outputToTextEdit(Ui::MainWindow *, List &);
    friend void outputToTableWidget(Ui::MainWindow *, List &);
    friend void outputToListView(Ui::MainWindow *, List &);

    friend void readFromTextEdit(Ui::MainWindow *, List &A);
    friend void readFromTableView(Ui::MainWindow *, List &A);

};
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_addR_clicked();
    void on_addL_clicked();
    void on_delR_clicked();
    void on_delL_clicked();
    void on_timesScalarButton_clicked();
    void on_outIndex_clicked();

    void on_checkBoxLR_stateChanged();
    void on_checkBoxOutputToTextEdit_stateChanged(int arg1);
    void on_radioButtonInputFromTextEdit_clicked();
    void on_radioButtonInputFromTableWidget_clicked();
    void on_checkBoxOutputToTableWidget_stateChanged(int arg1);

    void on_buttonBubbleSort_clicked();
    void on_buttonSelectionSort_clicked();

    void on_checkBoxOutputToListView_stateChanged(int arg1);

    void on_buttonMeanValue_clicked();

private:
    Ui::MainWindow *ui;
};
//--------------------------------------------------------------------------------

#endif // MAINWINDOW_H

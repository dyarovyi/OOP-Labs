#include "mainwindow.h"
#include "ui_mainwindow.h"


//--------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


//--------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}


//--------------------------------------------------------------------------------
void MainWindow::on_addR_clicked()
{
    //List L = readFromTextEdit();
    List L;
    ui >> L;

    bool ok;

    QString intText = ui->enterValue->toPlainText();
    int intVal = intText.toInt(&ok, 10);

    L + intVal;

    ui << L;
    ui->enterValue->setText("");
}


//--------------------------------------------------------------------------------
void MainWindow::on_addL_clicked()
{
    //List L = readFromTextEdit();
    // DELETE ALL ASTERIXES IF NOT DYNAMIC ALLOCATION OF MEMORY
    List *L = new List;
    ui >> *L;

    bool ok;

    QString intText = ui->enterValue->toPlainText();
    int intVal = intText.toInt(&ok, 10);

    *L - intVal;

    ui << *L;
    ui->enterValue->setText("");

    delete L;
}


//--------------------------------------------------------------------------------
void MainWindow::on_delR_clicked()
{
    //List L = readFromTextEdit();
    List L;
    ui >> L;

    L.deleteNodeRight();

    ui << L;
    ui->enterValue->setText("");
}


//--------------------------------------------------------------------------------
void MainWindow::on_delL_clicked()
{
    //List L = readFromTextEdit();
    List L;
    ui >> L;

    L.deleteNodeLeft();

    ui << L;
    ui->enterValue->setText("");
}


//--------------------------------------------------------------------------------
void MainWindow::on_timesScalarButton_clicked()
{
    //List L = readFromTextEdit();
    List L;
    ui >> L;

    bool ok;

    QString intText = ui->enterValue->toPlainText();
    int intVal = intText.toInt(&ok, 10);

    L.timesScalar(intVal);

    ui << L;
    ui->enterValue->setText("");
}


//--------------------------------------------------------------------------------
void MainWindow::on_outIndex_clicked()
{
    //List L = readFromTextEdit();
    List L;
    ui >> L;

    bool ok;

    QString intText = ui->enterValue->toPlainText();
    int index = intText.toInt(&ok, 10);

    ui->enterValue->setText("Element: " + QString::number(L.getValueOfElementIndex(index - 1)));

    ui << L;
}


//--------------------------------------------------------------------------------
void MainWindow::on_buttonMeanValue_clicked()
{
    List L;
    ui >> L;

    QString str;
    str.setNum(L.meanValue());
    ui->enterValue->setText("Mean value: " + str);

    ui << L;
}


//--------------------------------------------------------------------------------
void MainWindow::on_buttonBubbleSort_clicked()
{
    //List L = readFromTextEdit();
    List L;
    ui >> L;

    L.sortBubble();

    ui << L;
    ui->enterValue->setText("");
}


//--------------------------------------------------------------------------------
void MainWindow::on_buttonSelectionSort_clicked()
{
    //List L = readFromTextEdit();
    List L;
    ui >> L;

    L.sortSelection();

    ui << L;
    ui->enterValue->setText("");
}


//--------------------------------------------------------------------------------
void MainWindow::on_checkBoxLR_stateChanged()
{
    if (ui->checkBoxLR->isChecked())
    {
        List::setOutputLeftToRight(true);
        std::cout << "CheckBox state TRUE" << std::endl;
    }
    else
    {
        List::setOutputLeftToRight(false);
        std::cout << "CheckBox state FALSE" << std::endl;
    }
}



// Перевантаження <<
//--------------------------------------------------------------------------------
void operator << (Ui::MainWindow *ui, List &L)
{
    if (ui->checkBoxOutputToTextEdit->isChecked())
    {
        outputToTextEdit(ui, L);
    }

    if (ui->checkBoxOutputToTableWidget->isChecked())
    {
        outputToTableWidget(ui, L);
    }

    if (ui->checkBoxOutputToListView->isChecked())
    {
        outputToListView(ui, L);
    }
}


// Перевантаження >>
//--------------------------------------------------------------------------------
void operator >> (Ui::MainWindow *ui, List &A)
{
    if (ui->radioButtonInputFromTextEdit->isChecked())
    {
        readFromTextEdit(ui, A);
    }
    else
    {
        readFromTableView(ui, A);
    }
}


//--------------------------------------------------------------------------------
void MainWindow::on_checkBoxOutputToTextEdit_stateChanged(int arg1)
{
    ui->textEdit->setText("");
}


//--------------------------------------------------------------------------------
void MainWindow::on_checkBoxOutputToTableWidget_stateChanged(int arg1)
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
}


//--------------------------------------------------------------------------------
void MainWindow::on_checkBoxOutputToListView_stateChanged(int arg1)
{
    QStringList *stringList = new QStringList();
    stringList->append("");
    QStringListModel *listModel = new QStringListModel(*stringList, NULL);
    ui->listView->setModel(listModel);
}


//--------------------------------------------------------------------------------
void MainWindow::on_radioButtonInputFromTextEdit_clicked()
{
    ui->radioButtonInputFromTableWidget->setChecked(false);
}


//--------------------------------------------------------------------------------
void MainWindow::on_radioButtonInputFromTableWidget_clicked()
{
    ui->radioButtonInputFromTextEdit->setChecked(false);
}


//--------------------------------------------------------------------------------
void outputToTextEdit(Ui::MainWindow *ui, List &L)
{
    QString str = "";

    Node *current = NULL;

    if (List::outputLeftToRight)
    {
        current = L.head;
    }
    else
    {
        current = L.tail;
    }

    while (current != NULL)
    {
        str += QString::number(current->value) + "    ";

        ui->textEdit->setText(str);

        if (List::outputLeftToRight)
        {
            current = current->next;
        }
        else
        {
            current = current->previous;
        }
    }

}


//--------------------------------------------------------------------------------
void outputToTableWidget(Ui::MainWindow *ui, List &L)
{
    int row = 0;
    int column = 0;

    Node *current = NULL;

    if (List::outputLeftToRight)
    {
        current = L.head;
    }
    else
    {
        current = L.tail;
    }

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    ui->tableWidget->setRowCount(L.getCountElements() / 9 + 1);
    ui->tableWidget->setColumnCount(9);

    for (int i = 0; i < 9; i++)
    {
        ui->tableWidget->setColumnWidth(i ,40);
    }

    while (current != NULL)
    {
        ui->tableWidget->setItem(row, column, new QTableWidgetItem(QString::number(current->value)));
        column++;

        //cout << "ROW: " << row << " COLUMN: " << column << endl;

        if (column == 9)
        {
            column = 0;
            row++;
            ui->tableWidget->setRowCount(row+1);
        }

        if (List::outputLeftToRight)
        {
            current = current->next;
        }
        else
        {
            current = current->previous;
        }
    }
}


//--------------------------------------------------------------------------------
void outputToListView(Ui::MainWindow *ui, List &L)
{
    Node *current = NULL;

    if (List::outputLeftToRight)
    {
        current = L.head;
    }
    else
    {
        current = L.tail;
    }

    QStringList *stringList = new QStringList();

    while (current != NULL)
    {
        if (List::outputLeftToRight)
        {
            stringList->append(QString::number(current->value));
            current = current->next;
        }
        else
        {
            stringList->append(QString::number(current->value));
            current = current->previous;
        }
    }

    QStringListModel *listModel = new QStringListModel(*stringList, NULL);
    ui->listView->setModel(listModel);

//    delete stringList;
//    delete listModel;
}


//--------------------------------------------------------------------------------
void readFromTextEdit(Ui::MainWindow *ui, List &A)
{
    QString str = ui->textEdit->toPlainText();
    QTextStream stream(&str);

    while (!stream.atEnd())
    {
        int N;
        stream >> N;

        if (N != 0)
            A + N;
    }
}


//--------------------------------------------------------------------------------
void readFromTableView(Ui::MainWindow *ui, List &A)
{
    int row = 0;
    int column = 0;

    bool ok;
    int N;

    while (ui->tableWidget->item(row, column))
    {
        N = ui->tableWidget->item(row, column)->text().toInt(&ok, 10);

        if (N != 0)
            A + N;

        column++;
        if (column == 9)
        {
            column = 0;
            row++;
            ui->tableWidget->setRowCount(row+1);
        }
    }
}



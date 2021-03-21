#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFile = filename;

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filename);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    ui->textEdit->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionItalics_triggered()
{
    QTextCharFormat format;
    format.setFontItalic(true);
    ui->textEdit->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionUnderline_triggered()
{
    QTextCharFormat format;
    format.setFontUnderline(true);
    ui->textEdit->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionPlain_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(QFont::Light);
    format.setFontItalic(false);
    format.setFontUnderline(false);
    ui->textEdit->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer name");
    QPrintDialog pDialog(&printer, this);

    if (pDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this, "Warning", "Cannot access printer.");
         return;
    }
    ui->textEdit->print(&printer);
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica"), this);
    ui->textEdit->setFont(font);
}


void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::gray, this);
    ui->textEdit->setTextColor(color);
}

void MainWindow::on_actionFind_replace_triggered()
{
    bool ok;
    QString findString = QInputDialog::getText(this, tr("Find string"),
                                             tr("Find string:"), QLineEdit::Normal,
                                             tr(""), &ok);
    QString replaceString = QInputDialog::getText(this, tr("Replace string"),
                                                  tr("Replace string:"), QLineEdit::Normal,
                                                  tr(""), &ok);;
    ui->textEdit->moveCursor(QTextCursor::Start);
    while(ui->textEdit->find(findString))
    {
      ui->textEdit->textCursor().insertText(replaceString);
    }
}

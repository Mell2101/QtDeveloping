#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    list = { "Русский", "English" };
    ui->comboBox->addItems(list);

    ui->radioButton->setChecked(true);
    ui->checkBox->setChecked(true);

    qApp->installTranslator(&translator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_O)
    {
        this->on_pushButton_clicked();
    }
    if(event->key() == Qt::Key_S)
    {
        this->on_pushButton_5_clicked();
    }
    if(event->key() == Qt::Key_N)
    {
        this->on_pushButton_4_clicked();
    }
    if(event->key() == Qt::Key_Q)
    {
        this->close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    path = QFileDialog::getOpenFileName();
    if(path.isEmpty()) return;

    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);

        if(ui->checkBox->isChecked())
        {
            ui->plainTextEdit->setReadOnly(true);
        }
        else
        {
            ui->plainTextEdit->setReadOnly(false);
        }
        ui->plainTextEdit->setPlainText(text);

    }

}

void MainWindow::on_pushButton_2_clicked()
{

    QFile openFile(path);
    QFile newCreatFile(creatPath);

    if(openFile.open(QIODevice::WriteOnly))
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        openFile.write(ba, ba.length());
    }

    if(newCreatFile.open(QIODevice::WriteOnly))
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        newCreatFile.write(ba, ba.length());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox;
    QFile file(":/Help/Help.doc");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        msgBox.setText(text);
        msgBox.exec();

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->radioButton->isChecked()) formatFile = ".doc";
    if(ui->radioButton_2->isChecked()) formatFile = ".txt";

    creatPath = QFileDialog::getSaveFileName().append(formatFile);
    if(creatPath.isEmpty()) return;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->radioButton->isChecked()) formatFile = ".doc";
    if(ui->radioButton_2->isChecked()) formatFile = ".txt";

    QString saveAsFile = QFileDialog::getSaveFileName().append(formatFile);
    QFile openFile(saveAsFile);

    if(openFile.open(QIODevice::WriteOnly))
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        openFile.write(ba, ba.length());
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(list[0] == arg1)
    {
        translator.load(":/Language/QtLanguage_ru.qm");
    }
    if(list[1] == arg1)
    {
        translator.load(".");
    }
}


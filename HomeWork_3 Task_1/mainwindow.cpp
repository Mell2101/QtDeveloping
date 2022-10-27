#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
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
        ui->plainTextEdit->setPlainText(text);
    }

}


void MainWindow::on_pushButton_4_clicked()
{

    if(ui->radioButton->isChecked()) formatFile = ".doc";
    if(ui->radioButton_2->isChecked()) formatFile = ".txt";

    creatPath = QFileDialog::getSaveFileName().append(formatFile);
    if(creatPath.isEmpty()) return;

    QFile creatFile(creatPath);
    if(creatFile.open(QIODevice::WriteOnly))
    {
        QString firstText = "Hi! I created a new file";
        QByteArray ba = firstText.toUtf8();
        creatFile.write(ba);


        QString text(ba);
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


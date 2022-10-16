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
    QString fwid = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit_2->setPlainText(fwid);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString swid = ui->plainTextEdit_2->toPlainText();
    ui->plainTextEdit->setPlainText(swid);
}


void MainWindow::on_pushButton_3_clicked()
{

    QTextEdit var;
    var.setHtml("<big>Hello</b> <i>Qt!</i>");

    ui->plainTextEdit->setPlainText(var.toPlainText());
}


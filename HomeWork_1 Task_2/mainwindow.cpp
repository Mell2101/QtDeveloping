#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmath.h>

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
    double b_var = ui->lineEdit->text().toDouble();
    double c_var = ui->lineEdit_2->text().toDouble();
    double p_var = ui->lineEdit_3->text().toDouble();
    double a_var = 0;
    double cos_var = 0;

    if(ui->radioButton->isChecked()){
        double rad = p_var*(3.14/180);
        cos_var = qCos(rad);
    }else if(ui->radioButton_2->isChecked()){
        cos_var = qCos(p_var);
    }

    a_var = qSqrt(qPow(b_var,2) + qPow(c_var,2)
                  - 2*b_var*c_var * cos_var);
    QString a = QString::number(a_var);
    ui->lineEdit_4->setText(a);


}


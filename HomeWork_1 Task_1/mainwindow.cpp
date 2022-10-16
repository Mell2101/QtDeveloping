#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double a_var = ui->lineEdit->text().toDouble();
    double b_var = ui->lineEdit_2->text().toDouble();
    double c_var = ui->lineEdit_3->text().toDouble();

    double d_var = qPow(a_var,2)-4*b_var * c_var;
    QString d = QString::number(d_var);
    ui->lineEdit_5->setText(d);

    if(d_var < 0){
        ui->lineEdit_4->setText("No roots");
    }else if(d_var > 0){
        double x1_var = (-b_var - qSqrt(d_var))/(2*a_var);
        double x2_var = (-b_var + qSqrt(d_var))/(2*a_var);

        QString x1 = QString::number(x1_var);
        QString x2 = QString::number(x2_var);

        ui->lineEdit_6->setText(x1);
        ui->lineEdit_7->setText(x2);
    }else if(d_var = 0){

        double x_var = -b_var/2*a_var;
        ui->lineEdit_4->setText("Has one root");

        QString x = QString::number(x_var);
        ui->label_6->setText(x);
    }

}

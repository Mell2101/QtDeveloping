#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QStringList list {"C++", "Python", "C#",
                      "PHP", "JavaScript"};

    model = new QStandardItemModel(list.size(), 1, this);
    for(int i = 0; i < model->rowCount(); ++i)
    {
        QModelIndex index = model->index(i, 0);
        QString str = list[i];
        model->setData(index, str, Qt::DisplayPropertyRole);
        model->setData(index,str, Qt::ItemDataRole());
        model->setData(index, QIcon(":/LP/LP/"+str+".png"),
                       Qt::DecorationRole);
    }

    ui->checkBox->setChecked(true);

    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    int i = model->rowCount();
    model->insertRow(model->rowCount());
    QStringList list_1 { "" };

        QModelIndex index = model->index(i, 0);
        QString str = list_1[0];
        model->setData(index, str, Qt::DisplayPropertyRole);
        model->setData(index,str, Qt::ItemDataRole());
        model->setData(index, QIcon(":/LP/LP/"+str+".png"),
                       Qt::DecorationRole);
    i++;
   // QString lp = ui->listView->currentIndex().data().toString();


    ui->listView->setModel(model);
}


void MainWindow::on_pushButton_2_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->removeRow(row);
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
    {
        ui->listView->setViewMode(QListView::IconMode);
    }
    else
    {
        ui->listView->setViewMode(QListView::ListMode);
    }
}


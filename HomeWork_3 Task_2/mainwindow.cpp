#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QObject>

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
    QString url = "https://mail.ru";
    QString html = getHtml(url);
    if(html.isEmpty())
    {
        ui->plainTextEdit->setPlainText("Error");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        return;
    }

    QStringList dataCurrency = getInfoCurrency(html);
    QStringList dataWeather = getInfoWeather(html);
   // QString info = QString::number(dataWeather.size()) ;
    ui->plainTextEdit->setPlainText(html);

    ui->lineEdit->setText(dataCurrency[0]);
    ui->lineEdit_2->setText(dataCurrency[1]);

    ui->lineEdit_3->setText(dataWeather[0]);
    ui->lineEdit_4->setText(dataWeather[1]);
    ui->lineEdit_5->setText(dataWeather[2]);
}

QString MainWindow::getHtml(const QString& url)
{
    QNetworkAccessManager manager_0;
    QNetworkReply* response = manager_0.get(QNetworkRequest(QUrl(url)));

    QEventLoop event;
    QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    response->deleteLater();
    return response->readAll();

};


QStringList MainWindow::getInfoCurrency(const QString& html)
{

    //<span class="quotations__item__rate">62.10</span>
    //<span class="quotations__item__rate">60.61</span>
    QStringList list;
    QRegularExpression regex("(<span class=\"quotations__item__rate\">)([\\d.]+)(</span>)");
    QRegularExpressionMatchIterator i = regex.globalMatch(html);
    while(i.hasNext())
    {
        QRegularExpressionMatch mach = i.next();
        QString data = mach.captured(2);
        list.append(data);
    }
    return list;
}

QStringList MainWindow::getInfoWeather(const QString& html)
{

    //+3</span>
    QStringList list;
    QRegularExpression regex("(\.)(\\d)(</span>)");
    QRegularExpressionMatchIterator i = regex.globalMatch(html);
    while(i.hasNext())
    {
        QRegularExpressionMatch mach = i.next();
        QString data = mach.captured(1)+ mach.captured(2);
        list.append(data);
    }
    return list;
}

#include "downloader.h"
#include <QtNetwork/QNetworkReply>
#include <QDebug>
#include <QEventLoop>

Downloader::Downloader(QObject *parent)
    : QObject{parent}
{


}

QStringList Downloader::getHtml(const QString& search)
{

    const QString text = "https://yandex.ru/images/search?text="+search;

    QNetworkAccessManager* manag = new QNetworkAccessManager(this);
    QNetworkReply* replyOne = manag->get(QNetworkRequest(QUrl(text)));
    QEventLoop event;
    QObject::connect(replyOne, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    replyOne->deleteLater();
    replyOne->close();

    QByteArray dataHtml = replyOne->readAll();


    QRegularExpression reg("(//avatars.mds.yandex.net/i[[:punct:]]id=)([[:word:]]+)-([0-9][0-9][0-9][0-9][0-9][0-9][0-9])(-images-thumbs&amp;n=13)");
    QRegularExpressionMatchIterator i = reg.globalMatch(QString(dataHtml));

    while(i.hasNext())
    {
        QRegularExpressionMatch mach = i.next();
                QString data = mach.captured();
                _list.append(data);
                if(_list.size() == 3) break;
    }

    return _list;
}

//https://yandex.ru/images/search?text=%D0%BA%D0%BE%D1%82

void Downloader::download(QString& img)
{

    _manager = new QNetworkAccessManager(this);

    QString q = "https:" + img + "&amp;exp=1";
    QUrl url(q);
    QNetworkRequest request(url);
    QNetworkReply* reply = _manager->get(request);

    i++;
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), SIGNAL(downloadProgress(qint64, qint64)));
    connect(_manager, SIGNAL(finished(QNetworkReply*)), SLOT(slotFinished(QNetworkReply*)));

}


void Downloader::slotFinished(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NetworkError::NoError)
    {
        emit error();
    }
    else
    {
        emit done( reply->url(), reply->readAll());
    }
    reply->deleteLater();


}

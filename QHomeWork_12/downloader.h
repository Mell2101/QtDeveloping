#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QRegularExpression>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);

    void download(QString&);
    QStringList getHtml(const QString& search);

signals:
    void downloadProgress(qint64, qint64);
    void done(const QUrl&,const QByteArray&);
    void error();

private slots:
    void slotFinished(QNetworkReply*);

private:
    QNetworkAccessManager* _manager;
    QStringList _list;
    int i = 0;

};

#endif // DOWNLOADER_H

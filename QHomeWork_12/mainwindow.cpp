#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _downloader = new Downloader(this);
    _progress = new QProgressBar(this);
    _line = new QLineEdit(this);
    _button = new QPushButton("Start",this);



    connect(_button,SIGNAL(clicked()), SLOT(slotGo()));

    connect(_downloader,SIGNAL(downloadProgress(qint64,qint64)),
           SLOT(slotDownloadProgress(qint64,qint64)));
    connect(_downloader, SIGNAL(done(QUrl,QByteArray)),
            SLOT(slotDone(QUrl,QByteArray)));





    QGridLayout* _layout = new QGridLayout(this);
    _layout->addWidget(_line, 0, 0);
    _layout->addWidget(_button, 0, 1);
    _layout->addWidget(_progress, 1, 0, 1, 2);


    QWidget* wid = new QWidget(this);
    setCentralWidget(wid);
    wid->setLayout(_layout);






}

MainWindow::~MainWindow()
{
}

void MainWindow::showPic(const QString &path)
{

    QPixmap pix(path);
    pix = pix.scaled(pix.size());

    _labelOne = new QLabel(this);

    _labelOne->setPixmap(pix);
    _labelOne->setFixedSize(pix.size());
    _labelOne->show();






}

void MainWindow::slotGo()
{

    QStringList list = _downloader->getHtml(_line->text());

    _downloader->download(list[0]);

}

void MainWindow::slotError()
{
    QMessageBox::critical(this, "Error", "Error!");
}

void MainWindow::slotDownloadProgress(qint64 received, qint64 total)
{
    if(total <= 0 )
    {
        slotError();
        return;
    }
    _progress->setValue(100*received/total);
}

void MainWindow::slotDone(const QUrl &url,const QByteArray &ba)
{


    QFile file(url.path().section('/', -1));
    if(file.open(QIODevice::WriteOnly)){
        file.write(ba);
        file.close();
    }

    showPic(file.fileName());


}




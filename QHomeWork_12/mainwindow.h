#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QLabel>
#include <QMessageBox>
#include <QRegularExpression>

#include "downloader.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Downloader* _downloader;
    QProgressBar* _progress;
    QPushButton* _button;
    QLineEdit* _line;
    QGridLayout* _layout;
    QLabel* _labelOne;

    int i = 3;
    void showPic(const QString&);

private slots:
    void slotGo();
    void slotError();
    void slotDownloadProgress(qint64, qint64);
    void slotDone(const QUrl&,const QByteArray& );

};
#endif // MAINWINDOW_H

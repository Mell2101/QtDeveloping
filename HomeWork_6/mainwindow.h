#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QTranslator>
#include <QEvent>
#include <QApplication>
#include <QObject>
#include <QMenu>
#include <QAction>
#include <QKeySequence>
#include <QList>
#include <Qprinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    void changeEvent(QEvent * event) override;


private slots:
    void slotPushButtonClicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);



private:
    Ui::MainWindow *ui;

    QString _formatFile;
    QString _creatPath;
    QString _path;
    QString _file;

    QStringList _listLang;
    QStringList _theme;
    QStringList _menuLangu;
    QList<QKeySequence> _keys;

    QTranslator _translator;

    QMenu* _menu;
    QAction* _ptrNewFile;
    QKeySequence* _key;

    QAction* _creatButton(QString &buttonName, QKeySequence& key);

};
#endif // MAINWINDOW_H

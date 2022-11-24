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
#include <QPrinter>
#include <QPrintDialog>
#include <QToolBar>
#include <QPushButton>
#include <QTextDocument>
#include <QTextDocumentFragment>
#include <QFont>
#include <QFontDialog>
#include <QTime>
#include <QDate>

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

    void changeEvent(QEvent* event) override;

private slots:
    void slotPushButtonClicked();
    void slotChangeLanguage();
    void slotChangeTheme();
    void slotSet();


private:
    Ui::MainWindow *ui;

    QString _formatFile;
    QString _creatPath;
    QString _path;
    QString _file;

    QStringList _listLang;
    QStringList _theme;
    QStringList _menuLangu;
    QStringList _nameButton;
    QList<QKeySequence> _keys;

    QTranslator _translator;
    //menu
    QMenu* _menu;
    QAction* _ptrNewFile;
    QKeySequence* _key;

    //MenuButtonSeting
    QPushButton* _tButtonBar;
    QToolBar* _tMenuButtonBar;
    QAction* _tBarAction;
    QAction* _tMenuActionOne;

    //menuButtonOne
    QMenu* _tMenuBarOne;
    //menuButtonTwo
    QMenu* _tMenuBarTwo;

    //Format
    QFont _font;

    //Time and Date
    QDateTime _timeDate;

    QAction* _creatButton(QString &buttonName, QKeySequence& key );
    QAction* _creatButton(QString &buttonName, QMenu *tMenuBar = nullptr);
    QAction* _creatButtonOne(QString &buttonName);
    QAction* _creatButtonTwo(QString &buttonName);


};
#endif // MAINWINDOW_H

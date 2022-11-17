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

    void keyPressEvent(QKeyEvent* event) override;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString _formatFile;
    QString _creatPath;
    QString _path;

    QStringList _listLang;
    QStringList _theme;
    QStringList _style;

    QTranslator _translator;


};
#endif // MAINWINDOW_H

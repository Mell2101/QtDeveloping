#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _translator.load(":/Language/QtLanguage_ru.qm");
    qApp->installTranslator(&_translator);

    _listLang = { "Русский", "English" };
    _theme = {tr("Light"), tr("Dark")};
    _style = {tr("Normal"), tr("Evil Button")};


    ui->comboBox->addItems(_listLang);
    ui->comboBox_2->addItems(_theme);
    ui->comboBox_3->addItems(_style);

    ui->radioButton->setChecked(true);
    ui->checkBox->setChecked(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);

    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_O)
    {
        this->on_pushButton_clicked();
    }
    if(event->key() == Qt::Key_S)
    {
        this->on_pushButton_5_clicked();
    }
    if(event->key() == Qt::Key_N)
    {
        this->on_pushButton_4_clicked();
    }
    if(event->key() == Qt::Key_Q)
    {
        this->close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    _path = QFileDialog::getOpenFileName();
    if(_path.isEmpty()) return;

    QFile file(_path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);

        if(ui->checkBox->isChecked())
        {
            ui->plainTextEdit->setReadOnly(true);
        }
        else
        {
            ui->plainTextEdit->setReadOnly(false);
        }
        ui->plainTextEdit->setPlainText(text);

    }

}

void MainWindow::on_pushButton_2_clicked()
{

    QFile openFile(_path);
    QFile newCreatFile(_creatPath);

    if(openFile.open(QIODevice::WriteOnly))
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        openFile.write(ba, ba.length());
    }

    if(newCreatFile.open(QIODevice::WriteOnly))
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        newCreatFile.write(ba, ba.length());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox;
    QFile file(":/Help/Help.doc");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        msgBox.setText(text);
        msgBox.exec();

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->radioButton->isChecked()) _formatFile = ".doc";
    if(ui->radioButton_2->isChecked()) _formatFile = ".txt";

    _creatPath = QFileDialog::getSaveFileName().append(_formatFile);
    if(_creatPath.isEmpty()) return;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->radioButton->isChecked()) _formatFile = ".doc";
    if(ui->radioButton_2->isChecked()) _formatFile = ".txt";

    QString saveAsFile = QFileDialog::getSaveFileName().append(_formatFile);
    QFile openFile(saveAsFile);

    if(openFile.open(QIODevice::WriteOnly))
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        openFile.write(ba, ba.length());
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

    if(_listLang[0] == arg1)
    {
        _translator.load(":/Language/QtLanguage_ru.qm");
        _theme = {tr("Light"), tr("Dark")};
        _style = {tr("Normal"), tr("Evil Button")};


    }
    if(_listLang[1] == arg1)
    {
        _translator.load(".");
        _theme = {"Light", "Dark"};
        _style = {"Normal", "Evil Button"};
    }

    ui->comboBox_2->setItemText(0,_theme[0]);
    ui->comboBox_2->setItemText(1,_theme[1]);
    ui->comboBox_3->setItemText(0,_style[0]);
    ui->comboBox_3->setItemText(1,_style[1]);

    qApp->installTranslator(&_translator);

}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(_theme[0] == arg1)
    {
        setStyleSheet("QMainWindow { background-color: white }");
    }
    if(_theme[1] == arg1)
    {
        setStyleSheet("QMainWindow { background-color: black }"
                      "QCheckBox { color: white }"
                      "QRadioButton { color: white }"
                      "QLabel {color: white}" );
    }
}

void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    if(_style[0] == arg1)
    {
        qApp->setStyleSheet("QPushButton{}");

    }

    if(_style[1] == arg1)
    {

        qApp->setStyleSheet("QPushButton { background-color: red; "
                      "border-style: outset; border-width: 2px; border-radius: 10 px; border-color: "
                      "beige; font: bold 14 px; min-width: 10 em; padding: 6px }");

    }

}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _listLang = { "Русский", "English" };
    _keys = {_key->Open, _key->New, _key->Save, QKeySequence(Qt::CTRL + Qt::Key_A),
             _key->Print,_key->HelpContents , QKeySequence(Qt::CTRL + Qt::Key_Q)};

    ui->comboBox->addItems(_listLang);
    ui->comboBox_2->addItems(_theme);


    ui->radioButton->setChecked(true);
    ui->checkBox->setChecked(true);

    //Menu
    _menu = menuBar()->addMenu(_file);

    for(int i = 0; i < _menuLangu.size(); ++i)
    {
        _creatButton(_menuLangu[i], _keys[i]);
    }



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


void MainWindow::slotPushButtonClicked()
{
    QString buttonName = ((QAction*)sender())->text();

    if(buttonName == _menuLangu[0])
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
    if(buttonName == _menuLangu[1])
    {
        if(ui->radioButton->isChecked()) _formatFile = ".doc";
        if(ui->radioButton_2->isChecked()) _formatFile = ".txt";

        _creatPath = QFileDialog::getSaveFileName().append(_formatFile);
        if(_creatPath.isEmpty()) return;
        QFile creatFile(_creatPath);

        if(creatFile.open(QIODevice::WriteOnly))
            {
                QString firstText = "Hi! I created a new file";
                QByteArray ba = firstText.toUtf8();
                creatFile.write(ba);


                QString text(ba);
                ui->plainTextEdit->setPlainText(text);

            }
    }

    if(buttonName == _menuLangu[2])
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
    if(buttonName == _menuLangu[3])
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
    if(buttonName == _menuLangu[4])
    {
        QPrinter printer;
        QPrintDialog dlg(&printer, this);
        dlg.setWindowTitle("Print");
        if(dlg.exec() != QDialog::Accepted) return;
        ui->plainTextEdit->print(&printer);
    }

    if(buttonName == _menuLangu[5])
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

    if(buttonName == _menuLangu[6])
    {
        this->close();
    }

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

    if(_listLang[0] == arg1)
    {
        _translator.load(":/Language/QtLanguage_ru.qm");
        _theme = {tr("Light"), tr("Dark")};
        _menuLangu = { tr("Open File"), tr("New File"), tr("Save All"), tr("Save AS"), tr("Print"), tr("Help"),tr("Quit") };
        _file = tr("File");



    }
    if(_listLang[1] == arg1)
    {
        _translator.load(".");
        _theme = {"Light", "Dark"};
        _menuLangu = {"Open File", "New File", "Save All", "Save As", "Print" ,"Help", "Quit" };
        _file = "File";

    }

    ui->comboBox_2->setItemText(0,_theme[0]);
    ui->comboBox_2->setItemText(1,_theme[1]);


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

QAction *MainWindow::_creatButton(QString &buttonName, QKeySequence& key)
{
    _ptrNewFile = _menu->addAction(buttonName);
    _ptrNewFile->setShortcut(key);
    connect(_ptrNewFile, &QAction::triggered, this, &MainWindow::slotPushButtonClicked);

    return _ptrNewFile;
}



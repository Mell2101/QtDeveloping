#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //string
    _file = "File";
    _theme = {"Light","Dark"};
    _listLang = {"Русский", "English" };
    _menuLangu = {"Open File", "New File", "Save All", "Save As", "Print" ,"Help", "Quit" };
    _nameButton = {"Language", "Theme", "Font", "<", "-" ,">" ,"==", "CF" ,"VF"};

    //HotKeys
    _keys = {_key->Open, _key->New, _key->Save, QKeySequence(Qt::CTRL + Qt::Key_A),
             _key->Print,_key->HelpContents , QKeySequence(Qt::CTRL + Qt::Key_Q)};

    //MenuButton
    _tMenuBarOne = new QMenu(this);
    _tMenuBarTwo = new QMenu(this);

    //
    ui->radioButton->setChecked(true);
    ui->checkBox->setChecked(true);
    //

    //Menu
    _menu = menuBar()->addMenu(_file);
    for(int i = 0; i < _menuLangu.size(); ++i)
    { 
        _creatButton(_menuLangu[i], _keys[i]);

    }

    //MenuButton
    //one
    _tMenuButtonBar = addToolBar("Buttons");
    for(int i = 0; i < _listLang.size(); ++i)
    {
        _creatButtonOne(_listLang[i]);
    }
    _creatButton(_nameButton[0],_tMenuBarOne );
    //two
    for(int i = 0; i < _theme.size(); ++i)
    {
        _creatButtonTwo(_theme[i]);
    }
    _creatButton(_nameButton[1], _tMenuBarTwo);
    //font
    for(int i = 2; i < _nameButton.size(); ++i)
    {
        _creatButton(_nameButton[i]);
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
                ui->textEdit->setReadOnly(true);
            }
            else
            {
                ui->textEdit->setReadOnly(false);
            }
            ui->textEdit->setPlainText(text);

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
                ui->textEdit->setPlainText(text);

            }
    }

    if(buttonName == _menuLangu[2])
    {
        QFile openFile(_path);
        QFile newCreatFile(_creatPath);

        if(openFile.open(QIODevice::WriteOnly))
        {
            QString text = ui->textEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            openFile.write(ba, ba.length());
        }

        if(newCreatFile.open(QIODevice::WriteOnly))
        {
            QString text = ui->textEdit->toPlainText();
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
            QString text = ui->textEdit->toPlainText();
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
        ui->textEdit->print(&printer);
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

void MainWindow::slotChangeLanguage()
{
   QString buttonName = ((QAction*)sender())->text();
   if(buttonName == _listLang[0])
   {
       _translator.load(":/Language/QtLanguage_ru.qm");

   }

   if(buttonName == _listLang[1])
   {
       _translator.load(".");
   }

   qApp->installTranslator(&_translator);
}

void MainWindow::slotChangeTheme()
{
    QString buttonName = ((QAction*)sender())->text();

    if(buttonName == _theme[0])
    {
        setStyleSheet("QMainWindow { background-color: white }");
    }
    if(buttonName == _theme[1])
    {
        setStyleSheet("QMainWindow { background-color: black }"
                      "QCheckBox { color: white }"
                      "QRadioButton { color: white }"
                      "QLabel {color: white}" );
    }

}

void MainWindow::slotSet()
{
    QString buttonName = ((QPushButton*)sender())->text();
    if(buttonName == _nameButton[2])
    {
        _font = ui->textEdit->textCursor().charFormat().font();
        QFontDialog dialog(_font,this);

        bool check[] = {true};
        _font = dialog.getFont(check);

        if(check[0])
        {
            QTextCharFormat fmt = ui->textEdit->textCursor().charFormat();
            fmt.setFont(_font);

            ui->textEdit->textCursor().setCharFormat(fmt);

        }
    }

    if(buttonName == _nameButton[3])
        ui->textEdit->setAlignment(Qt::AlignLeft);
    if(buttonName == _nameButton[4])
        ui->textEdit->setAlignment(Qt::AlignCenter);
    if(buttonName == _nameButton[5])
        ui->textEdit->setAlignment(Qt::AlignRight);
    if(buttonName == _nameButton[6])
        ui->textEdit->setAlignment(Qt::AlignJustify);

    QTextCharFormat fmt;
    if(buttonName == _nameButton[7])
    {
        _font = ui->textEdit->textCursor().charFormat().font();
        fmt = ui->textEdit->textCursor().charFormat();


    }

    if(buttonName == _nameButton[8])
    {
        fmt.setFont(_font);
        ui->textEdit->textCursor().setCharFormat(fmt);
    }
}

QAction *MainWindow::_creatButton(QString &buttonName, QKeySequence& key)
{
    _ptrNewFile = _menu->addAction(buttonName);
    _ptrNewFile->setShortcut(key);
    connect(_ptrNewFile, &QAction::triggered, this, &MainWindow::slotPushButtonClicked);
    return _ptrNewFile;
}

QAction *MainWindow::_creatButton(QString &buttonName, QMenu *tMenuBar )
{
    _tButtonBar = new QPushButton(buttonName,this);
    _tBarAction = _tMenuButtonBar->addWidget(_tButtonBar);
    _tButtonBar->setMenu(tMenuBar);
    connect(_tButtonBar, &QPushButton::clicked, this, &MainWindow::slotSet);

    return _tBarAction;
}

QAction *MainWindow::_creatButtonTwo(QString &buttonName)
{
    _tMenuActionOne = _tMenuBarTwo->addAction(buttonName);
    connect(_tMenuActionOne, &QAction::triggered, this, &MainWindow::slotChangeTheme);
    return _tMenuActionOne;

}

QAction *MainWindow::_creatButtonOne(QString &buttonName)
{
    _tMenuActionOne = _tMenuBarOne->addAction(buttonName);
    connect(_tMenuActionOne, &QAction::triggered, this, &MainWindow::slotChangeLanguage);
    return _tMenuActionOne;
}





#include "mainwindow.h"
#include "symboltext.h"
#include "ui_mainwindow.h"
#include "symboltext.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt = ui->plainTextEdit->toPlainText();

    int pos = 0;

    while(1)
    {
        int fnd = txt.indexOf("#@", pos); //#@RUS$
        if(fnd == -1) return;
        pos = fnd + 1;
        int r = txt.indexOf("$", fnd);
        int space = txt.indexOf(" ", fnd);

        if((r < space || space == -1) && r != -1)
        {
            SymbolText st(txt.mid(fnd+2, r-fnd-2));
            QString answer = st.pasteSymbol();
            txt.insert(r+1, answer);
            txt.remove(fnd, r+1);
            ui->plainTextEdit->setPlainText(txt);
        }
    }

}


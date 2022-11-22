#include "mainwindow.h"
#include <QLocale>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scence = new QGraphicsScene(this);
    setScene(scence);

    fig_1 = new Figures(this);
    scence->addItem(fig_1);
    connect(fig_1, SIGNAL(reDraw()),this, SLOT(reDraw()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::reDraw()
{
    scence->update();
    update();
}







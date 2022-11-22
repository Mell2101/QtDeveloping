#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "figures.h"



class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void reDraw();

private:

    QGraphicsScene* scence;
    Figures* fig_1;

};
#endif // MAINWINDOW_H

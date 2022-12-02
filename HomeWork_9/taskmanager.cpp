#include "taskmanager.h"
#include <QDebug>
TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{
    _date = new QDate;
    _date->currentDate();

    _task = " Enter a new task";
    _path = "./Tasks.txt";

    file = new QFile(_path, this);
    if(!file->open(QIODevice::ReadWrite )) return;

    QByteArray by = file->readAll();
    _writeTask.append(by);




}

void TaskManager::setDate(QString day, QString month, QString year)
{
    _date = new QDate;
    _date->setDate(year.toInt(), month.toInt(), day.toInt());
}

void TaskManager::setTask(QString task)
{
    _task = task;
}

void TaskManager::setTreeTask(QString taskTree)
{
    _treeTask.append(taskTree);
}

void TaskManager::creatTask()
{
    _writeTask.append(_task + " " + _date->toString("dd, MM, yy") + "\n");
    _treeTask.clear();
}

void TaskManager::creatTaskTree()
{
    //if(_treeTask.isEmpty()) return;

    for(int i = 0; i < _treeTask.size(); ++i)
    {
        _writeTask.append( _treeTask[i] + "\n" );
    }
}

void TaskManager::saveAll()
{


    if(_writeTask.isEmpty()) return;

    for(int i = 0; i < _writeTask.size(); ++i)
    {

        QByteArray ba = _writeTask[i].toUtf8();
        file->write(ba);

    }
    _writeTask.clear();


}

QString TaskManager::progress()
{
    _progress = _writeTask.size() /10;
    return QString::number(_progress) + "%";
}


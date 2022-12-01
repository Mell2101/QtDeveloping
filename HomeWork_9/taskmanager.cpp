#include "taskmanager.h"

TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{
    _date = new QDate;
    _date->currentDate();

    _task = " Enter a new task";


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

void TaskManager::setTreeTask(QString &taskTree, int i)
{
    _treeTask[i] = taskTree;
}

void TaskManager::creatTask()
{
    _writeTask.append(_task + " " + _date->toString("dd, MM, yy") + "/n");

}

void TaskManager::creatTaskTree()
{
    for(int i = 0; i < _treeTask.size(); ++i)
    {
        _writeTask[i+1] = _treeTask[i] + "/n";
    }
}

void TaskManager::saveAll()
{
    file = new QFile(_path, this);

    if(file->open(QIODevice::WriteOnly )) {

        if(_writeTask.isEmpty()) return;

        QByteArray ba = _writeTask[0].toUtf8();
        file->write(ba);

    }
/*
    QDataStream stream(file);
    auto by = _writeTask[0].toUtf8();
    int len = by.length();
    stream.writeRawData((char*)&len, sizeof len);
    stream.writeRawData(by.data(), len);

    stream.writeRawData((char*)&len, sizeof len);
    stream.writeRawData(by.data(), len);
*/
}


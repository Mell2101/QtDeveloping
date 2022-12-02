#include "taskmanager.h"
#include <QDebug>
TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{

    _date = new QDate;
    _path = "./Tasks.txt";

    file = new QFile(_path, this);
    if(!file->open(QIODevice::ReadWrite )) return;

    while(!file->atEnd()){
        QByteArray by = file->readLine();
        _writeTask.append(by);
    }




    _numberOfTasks = _writeTask.size();

}

void TaskManager::setDate(QString day, QString month, QString year)
{
    _date = new QDate;
    if(day.isEmpty() || month.isEmpty() || year.isEmpty())
    {

        _status = "Sorry, but the date or the task entered incompletely. Try agane.";
        return;
    }
    _date->setDate(year.toInt(), month.toInt(), day.toInt());
}

void TaskManager::setTask(QString task)
{
    if(task.isEmpty())
    {
        _status = "Sorry, but the date or the task entered incompletely. Try agane.";
        return;
    }
    _task = task;
}

void TaskManager::setTreeTask(QString taskTree)
{
    _treeTask.append(taskTree);
}

QString TaskManager::getStatus()
{
    return _status;
}

QString TaskManager::getNumberOfTasks()
{
    return QString::number(_numberOfTasks);
}

void TaskManager::creatTask()
{
    _writeTask.append(_task + " run up to " + " "+ _date->toString("dd, MM, yy") + " " +
                      + " your progress" + " "+ QString::number(_progress) + "\n");
    _treeTask.clear();
}

void TaskManager::creatTaskTree()
{


    for(int i = 0; i < _treeTask.size(); ++i)
    {
        _writeTask.append( _treeTask[i] + "\n" );
    }
}

void TaskManager::saveAll()
{
    _numberOfTasks = _writeTask.size();

    for(int i = 0; i < _writeTask.size(); ++i)
    {

        QByteArray ba = _writeTask[i].toUtf8();
        file->write(ba);

    }


}

void TaskManager::setProgress(QString prog)
{
    _progress = prog.toDouble();

}


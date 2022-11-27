#include "taskmaneger.h"


TaskManeger::TaskManeger(QObject *parent)
    : QObject{parent}
{

    _task = "Creat the first task";
    _progress = "0";
    _dt = QDateTime::currentDateTime();
}


void TaskManeger::setTask(QString task)
{
    _task = task;
}

void TaskManeger::setTime(int day, int month, int year)
{
   QDate data;
   data.setDate(day, month, year);
    _dt.setDate(data);
}

QString TaskManeger::getProgress()
{
    return _progress;
}

void TaskManeger::setProgress(QString i)
{
    _progress = i;
}

void TaskManeger::creatTask()
{
    QString stringTask = _task + ", complete up to: " + _dt.toString("dd.mm.yyyy") + ". Current progress:" + _progress;


    _file = new QFile(_path,this);

    if(!_file->open(QIODevice::WriteOnly))
    {
        auto by = stringTask.toUtf8();
        _file->write(by);
    }




}

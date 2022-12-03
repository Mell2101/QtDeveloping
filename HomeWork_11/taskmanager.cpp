#include "taskmanager.h"
#include <QDebug>

TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{

    _date = new QDate;
    _path = "tasktable.db";


    file = new QFile(_path, this);


    if(!createConnection()) return;


    if(!file->exists()) {

        if(!creatTable()) return;
    }


    _model = new QSqlTableModel(this);
    _model->setTable("tasktable");
    _model->select();


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

QSqlTableModel* TaskManager::getModel()
{
    return _model;
}


bool TaskManager::createConnection()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("tasktable.db");
    if(!_db.open()){
        qDebug() << " 0";
        return false;
    }
    return true;

}

bool TaskManager::creatTable()
{
    QSqlQuery query;

    QString s = "CREATE TABLE tasktable ("
            "id INTEGER PRIMARY NOT KEY,"
            "task VARCHAR(12),"
            "date VARCHAR(15),"
            "progress VARCHAR(5);";

    if(!query.exec(s)){
        qDebug() << " 0";
        return false;

    }
    return true;

}

bool TaskManager::insertRecord()
{

    QSqlQuery query;
    QString s = "INSERT INTO tasktable (task, date, progress)"
                "VALUES('%1', '%2', '%3');";

    QString q = s.arg(_task).arg(_date->toString("dd, MM, yy")).arg(QString::number(_progress));

    if(!query.exec(q))
    {
        qDebug() << "0";
        return false;
    }

    return true;
}

void TaskManager::setProgress(QString prog)
{
    _progress = prog.toDouble();

}


#include "taskmanager.h"
#include <QDebug>
#include <QSqlError>
#include <QApplication>

TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{

    _date = new QDate;
    _path = "TaskTable.db";


    file = new QFile(_path, this);


    if(!createConnection()) return;

    if(!file->exists()){
        if(!creatTable()) return;
    }

    _table = new QTableView;


    _model = new QSqlTableModel(this);
    _model->setTable("TaskTable");
    _model->select();

    _table->setModel(_model);

    _numberOfTasks = _model->rowCount();

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



QString TaskManager::getStatus()
{
    return _status;
}

QString TaskManager::getNumberOfTasks()
{
    return QString::number(_numberOfTasks);
}

bool TaskManager::createConnection()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("TaskTable.db");
    if(!_db.open()){
        qDebug() << " 0";
        return false;
    }
    return true;

}

bool TaskManager::creatTable()
{
    QSqlQuery query;

    QString s = "CREATE TABLE TaskTable ("
                "id INTEGER PRIMARY KEY NOT NULL,"
                "task VARCHAR(100),"
                "date VARCHAR(20),"
                "progress VARCHAR(20)"
                ");";




    if(!query.exec(s)){
        qDebug() << query.lastError().text() << "0";
        return false;

    }
    qDebug() << query.lastError().text() << "0";
    return true;

}

void TaskManager::showTasks()
{
    _table->show();
}

bool TaskManager::insertRecord()
{

    if(_date->isNull() || _path.isEmpty())
    {
        qDebug() << "0";
        return false;
    };

    QSqlQuery query;
    QString s = "INSERT INTO TaskTable (task, date, progress)"
                "VALUES('%1', '%2', '%3')";

    QString q = s.arg(_task).arg(_date->toString("dd, MM, yy")).arg(QString::number(_progress));


    if(!query.exec(q))
    {
        qDebug() << query.lastError().text()  << "0";
        return false;
    }

    return true;
}

void TaskManager::setProgress(QString prog  = "0")
{
    _progress = prog.toDouble();

}


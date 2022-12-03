#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include <QDate>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QQmlContext>
#include <QQmlEngine>


class TaskManager : public QObject
{
    Q_OBJECT

public:
    explicit TaskManager(QObject *parent = nullptr);

    Q_INVOKABLE void setDate(QString day, QString month, QString year);
    Q_INVOKABLE void setTask(QString task);
    Q_INVOKABLE void setTreeTask(QString taskTree);
    Q_INVOKABLE void setProgress(QString prog);


    Q_INVOKABLE QString getStatus();
    Q_INVOKABLE QString getNumberOfTasks();

    Q_INVOKABLE bool insertRecord();

    Q_INVOKABLE QSqlTableModel* getModel();




signals:

private:

    QStringList _writeTask;
    QStringList _treeTask;

    int _progress;
    int _numberOfTasks;

    QFile *file;
    QDate *_date;

    QString _task;
    QString _path;
    QString _status;

    QSqlDatabase _db;





    Q_INVOKABLE bool createConnection();
    Q_INVOKABLE bool creatTable();


    QSqlTableModel* _model;


};

#endif // TASKMANAGER_H

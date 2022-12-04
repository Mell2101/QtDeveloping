#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include <QDate>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QQmlContext>
#include <QTableView>


class TaskManager : public QObject
{
    Q_OBJECT

public:
    explicit TaskManager(QObject *parent = nullptr);

    Q_INVOKABLE void setDate(QString day, QString month, QString year);
    Q_INVOKABLE void setTask(QString task);
    Q_INVOKABLE void setProgress(QString prog);


    Q_INVOKABLE QString getStatus();
    Q_INVOKABLE QString getNumberOfTasks();

    Q_INVOKABLE bool insertRecord();

    Q_INVOKABLE bool createConnection();
    Q_INVOKABLE bool creatTable();
    Q_INVOKABLE void showTasks();



signals:

private:

    int _progress;
    int _numberOfTasks;

    QFile *file;
    QDate *_date;

    QString _task;
    QString _path;
    QString _status;

    QSqlDatabase _db;

    QTableView* _table;
    QSqlTableModel* _model;


};

#endif // TASKMANAGER_H

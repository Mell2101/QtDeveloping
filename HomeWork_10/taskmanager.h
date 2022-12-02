#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include <QDate>
#include <QFile>


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

    Q_INVOKABLE void creatTask();
    Q_INVOKABLE void creatTaskTree();
    Q_INVOKABLE void saveAll();


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



};

#endif // TASKMANAGER_H

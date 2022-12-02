#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include <QDate>
#include <QFile>
#include <QIODevice>

class TaskManager : public QObject
{
    Q_OBJECT
public:
    explicit TaskManager(QObject *parent = nullptr);

    Q_INVOKABLE void setDate(QString day, QString month, QString year);
    Q_INVOKABLE void setTask(QString task);
    Q_INVOKABLE void setTreeTask(QString taskTree);


    Q_INVOKABLE void creatTask();
    Q_INVOKABLE void creatTaskTree();
    Q_INVOKABLE void saveAll();
    Q_INVOKABLE QString progress();

signals:

private:
    QString _task;
    QStringList _writeTask;
    QStringList _treeTask;
    QDate *_date;
    int _progress;
    QFile *file;

    QString _path;


};

#endif // TASKMANAGER_H

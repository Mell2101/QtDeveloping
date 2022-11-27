#ifndef TASKMANEGER_H
#define TASKMANEGER_H

#include <QObject>
#include <QDateTime>
#include <QFile>


class TaskManeger : public QObject
{
    Q_OBJECT
public:
    explicit TaskManeger(QObject *parent = nullptr);



    Q_INVOKABLE void setTask(QString task);
    Q_INVOKABLE void setTime(int day, int month, int year);

    QString getProgress();
    Q_INVOKABLE void setProgress(QString i);

    Q_INVOKABLE void creatTask();

signals:
    void initEnd(bool succed);
   // void loadTown(QString town, QString info);

private:

    QString _task, _progress;
    QDateTime _dt;
    QString _path = ":/new/prefix1/TaskFile.txt";
    QFile* _file;

};

#endif // TASKMANEGER_H

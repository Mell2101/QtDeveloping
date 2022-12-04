#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include "taskmanager.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QApplication a(argc, argv);

    qmlRegisterType<TaskManager>("TaskManeger", 1,0 ,"TaskManager");

    QQmlApplicationEngine engine;
    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}

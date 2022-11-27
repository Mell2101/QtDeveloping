#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "taskmaneger.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<TaskManeger>("TaskManeger", 1, 0, "TaskManeger");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QHomeWork_9/main.qml"_qs);


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}

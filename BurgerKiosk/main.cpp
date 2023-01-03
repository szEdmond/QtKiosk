#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mycontroller.h"
#include "itemmanager.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<myController>("Singleton", 1, 0 ,"MyController");

    ItemManager::GetSingleton()->InitBurgers(qApp->applicationDirPath()+"/burgers.txt");
    ItemManager::GetSingleton()->InitSides(qApp->applicationDirPath()+"/sides.txt");
    ItemManager::GetSingleton()->InitDrinks(qApp->applicationDirPath()+"/drinks.txt");
    ItemManager::GetSingleton()->InitExtras(qApp->applicationDirPath()+"/ingredients.txt");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

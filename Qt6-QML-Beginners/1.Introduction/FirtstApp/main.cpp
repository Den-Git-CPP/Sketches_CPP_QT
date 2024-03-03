#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

//
#ifdef PROJECT_NAME
#define name PROJECT_NAME
#else
#define name "QMLBasic"
#endif

int main (int argc, char* argv [])
{
    QGuiApplication app (argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect (
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
      [] () {
          QCoreApplication::exit (-1);
      },
      Qt::QueuedConnection);
    engine.loadFromModule (name, "Main");

    return app.exec ();
}

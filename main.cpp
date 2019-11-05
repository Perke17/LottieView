#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "lottiemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<LottieModel>("qt.io.qtws", 20, 19, "LottieModel");

    LottieModel *m = new LottieModel();
    engine.rootContext()->setContextProperty("lottiefiles", m);

    engine.load(url);

    return app.exec();
}

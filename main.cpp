#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include <nge/controller/nodegraphcontroller.h>
#include <nge/model/uinode.h>
#include <nge/model/uinodemodel.h>
#include <nge/model/uiedgemodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    
    qRegisterMetaType<UINodeModel>("UINodeModel");
    qRegisterMetaType<UIEdgeModel>("UIEdgeModel");
    
    qmlRegisterType<NodeGraphController>("nge", 1,0, "NodeGraphController");
    
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QQuickWindow* window = dynamic_cast<QQuickWindow*>(engine.rootObjects().first());
    QSurfaceFormat format;
    format.setSamples(16);

    window->setFormat(format);

    return app.exec();
}

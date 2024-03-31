#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mediaplayercontrol.h"

#include "applicationmodel.h"
#include "applicationbar.h"
#include "mediaplayercontrol.h"
#include "widgetbar.h"
#include "eventdata.h"

#include "appuicontrol.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    ApplicationBar   appBar;

    WidgetBar        widgetBar;

    AppUIControl     appUIControl(&appBar, &widgetBar);

    QQmlApplicationEngine engine;

    // application bar
    engine.rootContext()->setContextProperty("appModel", &ApplicationModel::getInstance());

    // application
    engine.rootContext()->setContextProperty("appUIControl", &appUIControl);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

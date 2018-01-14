#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include "map.h"
#include "mapprovider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    Map map;
    //添加Provider，注意字符串中的大小写，qml中使用要一致
    view.engine()->addImageProvider(QLatin1String("Provider"), map.getProvider());
    view.engine()->rootContext()->setContextProperty("IMap", &map);
    view.setSource(QUrl("qrc:/Qml/Main.qml"));
    view.show();

    return app.exec();
}

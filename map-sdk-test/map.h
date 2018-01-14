#ifndef MAP_H
#define MAP_H
#include <memory>
#include <cstdlib>
#include <functional>

#include <QUrl>
#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "mapprovider.h"

class Map : public QObject
{
    Q_OBJECT
public:
    explicit Map(QObject *parent = nullptr);
     //获取 provider
    MapProvider * getProvider();
    //INVOKABLE 开放给qml，用来发起GET 请求
    Q_INVOKABLE void get(QUrl url);
signals:
    void replayReady();
public slots:
    void replaySlot(QNetworkReply *reply);
private:
    //C++ std 风格的智能指针
    std::shared_ptr<QNetworkAccessManager> mManager;
    std::shared_ptr<MapProvider> mMapProvider;
};
#endif // MAP_H

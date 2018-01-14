#include "map.h"

Map::Map(QObject *parent) : QObject(parent)
{
    //指针初始化
    mManager = std::make_shared<QNetworkAccessManager>();
    mMapProvider = std::make_shared<MapProvider>();
    //连接信号 槽
    connect(mManager.get(), &QNetworkAccessManager::finished, this, &Map::replaySlot);
}

MapProvider *Map::getProvider()
{
    return mMapProvider.get();
}

void Map::get(QUrl url)
{
    //GET 请求
    mManager->get(QNetworkRequest(QUrl(url)));
}
// GET请求的响应处理
void Map::replaySlot(QNetworkReply *reply)
{
    //读取全部数据，写入provider
    mMapProvider->setData(reply->readAll());
    //通知qml，刷新图片
    emit replayReady();
}

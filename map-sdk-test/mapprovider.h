#ifndef MAPPROVIDER_H
#define MAPPROVIDER_H

#include <QFile>
#include <QDebug>
#include <QQuickImageProvider>
class MapProvider : public QQuickImageProvider {
public:
    MapProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap) {
        //pixmap 初始化为800 x 600 的红色图片
        mPixmap = QPixmap(800, 600);
        mPixmap.fill(QColor("red"));
    }
     //重载， qml就是通过这个函数得到的图片
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    override {
        return mPixmap;
    }
    //将数据设置到pixmap中
    void setData(QByteArray data) {
        mPixmap.loadFromData(data);
    }
private:
    QPixmap mPixmap;
};


#endif // MAPPROVIDER_H

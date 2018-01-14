import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    visible: true
    width: 1024
    height: 768

    readonly property var key : "key"

    Connections {
        target: IMap
        onReplayReady: {
            image.source = "image://Provider";
        }
    }
    Image {
        id: image
        width: 800
        height: 600
        anchors.centerIn: parent

        Component.onCompleted: {
            var url = "http://restapi.amap.com/v3/staticmap?location=116.481485,39.990464&zoom=10&size=800*600&markers=mid,,A:116.481485,39.990464&key=" + key;
            IMap.get(url);
        }
    }
}

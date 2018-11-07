import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    anchors.fill: parent
    visible: false;
    z: 2

    property int biHeight: 40
    property int biWidht: 40

    BusyIndicator { anchors.centerIn: parent; width: biWidht; height: biHeight }
    MouseArea     { anchors.fill: parent                                       }
}


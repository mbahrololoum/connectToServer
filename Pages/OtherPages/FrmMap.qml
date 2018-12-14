import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtPositioning 5.8
import QtLocation 5.9
import QtGraphicalEffects 1.0

import Company.ServiceMap 1.0

Item {
    id: mapPage
    Component.onCompleted: serviceMap.request()
    Component.onDestruction :  {
        map.clearMapItems() ;
        if(src.position.coordinate === "")
        {
            coord[0] = "35.7120645"
            coord[1] = "51.4144933"
        }
        else
        {
            coord[0] = src.position.coordinate.latitude
            coord[1] = src.position.coordinate.longitude
        }
    }

    property variant coord        : []
    property int     pId          : 0
    property string  pPhoto       : ""
    property string  pTitle       : ""
    property string  pDescription : ""
    property string  pRating      : ""
    property string  pLocation    : ""
    property string  filterItem   : "all"

    ButtonGroup { id: filterButtons }

    ServiceMap  { id: serviceMap    }

    Plugin {
        id: myPlugin
        name: "osm"

        //provide the address of the tile server to the plugin
        PluginParameter { name: "osm.mapping.custom.host";                  value: "http://localhost/osm/"               }
        /*disable retrieval of the providers information from the remote repository.
        If this parameter is not set to true (as shown here), then while offline,
        network errors will be generated at run time*/
        PluginParameter { name: "osm.mapping.providersrepository.disabled"; value: true                                  }
        PluginParameter { name: "osm.useragent";                            value: "My great Qt OSM application"         }
        PluginParameter { name: "osm.mapping.host";                         value: "http://osm.tile.server.address/"     }
        PluginParameter { name: "osm.mapping.copyright";                    value: "All mine"                            }
        PluginParameter { name: "osm.routing.host";                         value: "http://osrm.server.address/viaroute" }
        PluginParameter { name: "osm.geocoding.host";                       value: "http://geocoding.server.address"     }
    }

    PositionSource {
        id: src
        updateInterval: 1000
        active: true
        onPositionChanged: {
            console.log("----------- onPositionChanged -----------")
            coord[0] = src.position.coordinate.latitude
            coord[1] = src.position.coordinate.longitude
            mypin.coordinate = src.position.coordinate
            map.update();
        }
    }

    Map {
        id: map
        plugin: myPlugin;
        anchors.fill: parent
        zoomLevel: 15
        center: QtPositioning.coordinate(coord[0], coord[1])

        MapQuickItem {
            id: mypin
            coordinate: QtPositioning.coordinate(coord[0], coord[1])
            anchorPoint.x: rect.width * 0.5
            anchorPoint.y: rect.height * 0.5
            z : 6
            sourceItem: Rectangle { id: rect; width: 18; height: 18; radius: 9; color: "#4a80f5"; border.width: 2; border.color: "white" }
            onCoordinateChanged:   map.update()
        }

        MapItemView {
            id:mapItemView
            model: serviceMap.modelMap
            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(latitude ,longitude)
                anchorPoint.x: pinImage.width * 0.5
                anchorPoint.y: pinImage.height
                sourceItem: Column {
                    spacing: 2

                    Item {
                        id: pinImage
                        height: 60
                        width:  60
                        anchors.horizontalCenter: parent.horizontalCenter

                        Rectangle     { id: imageLogoFrame;    anchors.fill: parent;  color : "orange"; visible: false }
                        Image         { id: logoImg;           anchors.fill: parent;  source: "qrc:/Image/Map/pinLocationStore.svg"; visible: true; fillMode: Image.PreserveAspectFit; asynchronous: true }
                        OpacityMask   { anchors.fill: logoImg; maskSource: logoImg;   source: imageLogoFrame  }

                        Rectangle {
                            id: storeImage
                            height: 40
                            width:  40
                            radius: 20
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.top: parent.top
                            anchors.topMargin: 2

                            Image  { id: logoImg2; anchors.fill: parent; source: "qrc:/Image/profile/user-" + id + ".svg" ; fillMode: Image.PreserveAspectFit; sourceSize: "30x30" }
                        }

                        MouseArea{
                            anchors.fill: parent
                            ToolTip.timeout: 5000
                            ToolTip.visible: pressed
                            ToolTip.text: title
                        }
                    }
                }
                onCoordinateChanged: { map.update(); update() }
            }
            Component.onCompleted: update()
        }

        Rectangle {
            id: myLocationImage
            width: 35
            height: 35
            z: 20
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 30
            radius: 20; color: "#232F3F"

            Image     { id: myLocationImg; asynchronous: true; source: "qrc:/Image/Map/myLocationPin.svg"; sourceSize: "25x25"; anchors.centerIn: parent }

            MouseArea {
                anchors.fill: parent
                onClicked: {

                    map.center = QtPositioning.coordinate(coord[0], coord[1])
                    map.zoomLevel =16
                    console.log(coord[0])
                    console.log(coord[1])
                }
                onPressed:  myLocationImg.scale = 0.9
                onReleased: myLocationImg.scale = 1
            }
        }
    }
}

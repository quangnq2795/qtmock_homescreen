import QtQuick 2.15
import QtQuick.Window 2.15
import QtQml.Models 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtLocation 5.15
import QtPositioning 5.11

Window {
    id: windows
    width: 1920
    height: 1080
    visible: appUIControl.isVisible

    Rectangle {
        id: homeScreen

        anchors.fill: parent

        Image {
            anchors.fill: parent
            source: "qrc:/Image/appbar/background.jpg"
        }

        Rectangle {

            id: statusBar
            width: parent.width
            height: 60
            color: "#C5BCBC"

            Rectangle {
                id: statusBarTimer
                width: 255
                height: 93
                color: "#A19D9D"

                anchors.right: parent.horizontalCenter

                Text {
                    text: "12:23 AM"
                    font {
                        family: "Sawarabi Mincho"
                        pixelSize: 40
                    }

                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: statusBarDate
                width: 255
                height: 93
                color: "#A19D9D"

                anchors.left: parent.horizontalCenter

                Text {
                    text: "APR. 20"
                    font {
                        family: "Sawarabi Mincho"
                        pixelSize: 40
                    }

                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }

        Item {
            id: widgetBar

            width: 1920
            height: 523

            anchors.top: statusBar.bottom
            anchors.topMargin: 50

            Rectangle {
                id: firstwidget
                width: 523
                height: 523

                anchors.left: parent.left
                anchors.leftMargin: 15


                border.color: "#C5BCBC"
                border.width: 1

                Map {
                    anchors.fill: parent
                    copyrightsVisible : false
                    plugin: Plugin {
                        name: "mapboxgl"
                    }


                    center: QtPositioning.coordinate(21.019631, 105.784136)  // Hanoi coordinates
                    zoomLevel: 12
                }

            }

            Item {
                id: secondWidget

                width: 746
                height: 523

                anchors.left: firstwidget.right
                anchors.leftMargin: 49

                Rectangle {
                    id: secondWidgetBackground

                    anchors.fill: parent

                    border.color: "#C5BCBC"
                    border.width: 1
                    color: "#5A5454"
                    opacity: 0.7
                }

                Item {
                    id: secondWidgetContent
                    anchors.fill: parent


                    Item {
                        id: secondWidgetTitle


                        width: 746
                        height: 102

                        anchors.top: parent.top

                        Text {
                            text: "Climate"
                            font {
                                family: "Sawarabi Mincho"
                                pixelSize: 35
                            }

                            color: "white"

                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }


                    Item {
                        id: secondWidgetBody

                        width: 746
                        height: 303

                        anchors.top: secondWidgetTitle.bottom

                        Item {
                            id: secondWidgetBodyDriver
                            width: 217
                            height: 303

                            anchors.left: parent.left
                            anchors.leftMargin: 19

                            Text {
                                text: "DRIVER"
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.top: parent.top
                                anchors.topMargin: 28

                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 25
                                }

                                color: "white"
                            }

                            Image {
                                width: 218
                                height: 155
                                anchors.top: parent.top
                                anchors.topMargin: 77

                                source: "qrc:/Image/widgetbar/climate/ico_climate_01.png"
                            }

                            Text {
                                text: "LOW"
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 28

                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 25
                                }

                                color: "white"
                            }
                        }

                        Item {
                            id: secondWidgetBodyImage
                            width: 272
                            height: 303

                            anchors.left:secondWidgetBodyDriver.right

                            Image {
                                id: secondWidgetBodyWindLevelImage
                                width: 272
                                height: 155
                                anchors.top: parent.top
                                anchors.topMargin: 77
                                source: "qrc:/Image/widgetbar/climate/widget_climate_wind_level_09.png"
                            }

                            Image {
                                id: secondWidgetBodyWindLevelIcon
                                width: 61
                                height: 61
                                anchors.top: secondWidgetBodyWindLevelImage.bottom
                                anchors.horizontalCenter: parent.horizontalCenter
                                source: "qrc:/Image/widgetbar/climate/ico_wind_level.png"
                            }
                        }

                        Item {

                            id: secondWidgetBodyPassenger

                            width: 217
                            height: 303

                            anchors.right: parent.right
                            anchors.rightMargin: 19

                            Text {
                                text: "PASSENGER"

                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 25
                                }

                                color: "white"
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.top: parent.top
                                anchors.topMargin: 28
                            }

                            Image {
                                width: 218
                                height: 155
                                anchors.top: parent.top
                                anchors.topMargin: 77
                                source: "qrc:/Image/widgetbar/climate/ico_climate_01.png"
                            }

                            Text {
                                text: "20.5°C"
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 28

                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 25
                                }

                                color: "white"
                            }
                        }
                    }

                    Item {

                        id: secondWidgetFooter
                        width: 746
                        height: 118

                        anchors.top: secondWidgetBody.bottom

                        Item {
                            id: secondWidgetFooterLeft

                            width: 217
                            height: 118

                            anchors.left: parent.left
                            anchors.leftMargin: 19

                            Text {
                                text: "AUTO"
                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 35
                                }

                                color: "white"

                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter

                            }
                        }

                        Item {

                            id: secondWidgetFooterCenter

                            width: 273
                            height: 118

                            anchors.centerIn: parent

                            Text {
                                text: "OUTSIZE"
                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 30
                                }

                                color: "white"

                                anchors.horizontalCenter: parent.horizontalCenter

                                anchors.top: parent.top
                                anchors.topMargin: 15

                            }

                            Text {
                                text: "20.5°C"
                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 30
                                }

                                color: "white"

                                anchors.horizontalCenter: parent.horizontalCenter

                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 15

                            }
                        }

                        Item {
                            id: secondWidgetFooterRight

                            width: 217
                            height: 118

                            anchors.right: parent.right
                            anchors.rightMargin: 19

                            Text {
                                text: "SYNC"

                                font {
                                    family: "Sawarabi Mincho"
                                    pixelSize: 35
                                }

                                color: "white"

                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter

                            }
                        }

                    }

                }
            }

            Item {
                id: thirdWidget
                width: 523
                height: 523

                anchors.left: secondWidget.right
                anchors.leftMargin: 49

                Image {
                    anchors.fill: parent

                    source: "file:///" + appUIControl.songImage
                    opacity: 0.7
                }



                Image {
                    width: 251
                    height: 251

                    anchors.centerIn: parent

                    source: "file:///" + appUIControl.songImage
                }

                Image {
                    id: mediawidget_previous_button
                    width: 48
                    height: 51
                    source:"qrc:/Image/widgetbar/media/media-previous.png"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 40

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            homeScreen.setUIEvent("widgetbar", "mediawidget","previous");
                        }
                        onPressed: {
                            mediawidget_previous_button.source = "qrc:/Image/widgetbar/media/button-previous-hover.png"
                        }

                        onReleased: {
                            mediawidget_previous_button.source = "qrc:/Image/widgetbar/media/media-previous.png"
                        }
                        onEntered: {
                            cursorShape = Qt.PointingHandCursor;
                        }

                        onExited: {
                            cursorShape = Qt.ArrowCursor;

                        }

                    }
                }

                Image {
                    id: mediawidget_next_button
                    width: 48
                    height: 51

                    source:"qrc:/Image/widgetbar/media/media-next.png"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 40

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            homeScreen.setUIEvent("widgetbar", "mediawidget","next");
                        }

                        onPressed: {
                            mediawidget_next_button.source = "qrc:/Image/widgetbar/media/button-next-hover.png"

                        }

                        onReleased: {
                            mediawidget_next_button.source = "qrc:/Image/widgetbar/media/media-next.png"
                        }

                        onEntered: {
                            cursorShape = Qt.PointingHandCursor;
                        }

                        onExited: {
                            cursorShape = Qt.ArrowCursor;
                        }

                    }
                }

                Image {
                    id: mediawidget_play_button
                    width: 48
                    height: 51

                    source:"qrc:/Image/widgetbar/media/media-next.png"
                    anchors.centerIn: parent
                    property bool isPlaying: appUIControl.songPlaying;

                    onIsPlayingChanged: {
                        if(appUIControl.songPlaying) {
                            mediawidget_play_button.source = "qrc:/Image/widgetbar/media/button-pause.png"
                        } else {
                            mediawidget_play_button.source = "qrc:/Image/widgetbar/media/media-next.png"
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {


                            if (appUIControl.songPlaying) {
                                homeScreen.setUIEvent("widgetbar", "mediawidget","pause");
                            } else {
                                homeScreen.setUIEvent("widgetbar", "mediawidget","play");
                            }
                        }


                        onEntered: {
                            cursorShape = Qt.PointingHandCursor;
                        }

                        onExited: {
                            cursorShape = Qt.ArrowCursor;
                        }

                    }
                }

                Text {
                    text: "USB Device"
                    font {
                        family: "Sawarabi Mincho"
                        pixelSize: 30
                    }

                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 50

                    color: "white"

                }

                Text {
                    text: appUIControl.songSinger
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 100

                    font {
                        family: "Sawarabi Mincho"
                        pixelSize: 25
                    }

                    color: "white"

                }

                

                Text {
                    text: appUIControl.songTitle
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 50

                    font {
                        family: "Sawarabi Mincho"
                        pixelSize: 25
                    }

                    color: "white"

                }

                ProgressBar {
                    width: 352
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 21
                }
            }
        }

        Item {
            width: 1920
            height: 320

            anchors.bottom: homeScreen.bottom
            anchors.bottomMargin: 20

            ListView {
                id: listView
                width: parent.width
                height: parent.height

                orientation: ListView.Horizontal

                property int dragIndex: -1

                model: appModel

                move: Transition {
                    NumberAnimation { properties: "x"; duration: 200 }
                }

                delegate: Item {
                    id: itemDelegate
                    width: 290
                    height: 320

                    Drag.active: dragArea.drag.active

                    MouseArea {
                        id: dragArea

                        anchors.fill: parent

                        drag.target: parent

                        drag.axis: Drag.XAxis

                        onClicked: {
                            homeScreen.setUIEvent("appbar",model.appid,"clicked");
                        }


                        onPressed: {

                            listView.dragIndex= index;
                            console.log("start source "+ listView.dragIndex)
                        }

                        onReleased: {

                            listView.dragIndex = -1;
                        }
                    }

                    Rectangle {
                        anchors.fill: parent
                        border.color: "#C5BCBC"
                        border.width: 1
                        radius: 20
                        color: "#777574"
                        opacity: 0.5
                    }

                    Image {

                        width: 138
                        height: 133
                        //source: model.iconSource
                        source: "file:///" + model.iconSource

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    DropArea {
                        anchors.fill: parent

                        onEntered: {

                            if(listView.dragIndex !== index) {
                                let targetIndex= index

                                console.log("targetindex "+ targetIndex)
                                console.log("source "+ listView.dragIndex)

                                if (listView.dragIndex !== targetIndex) {
                                    listView.model.move(targetIndex,listView.dragIndex,1);
                                    listView.dragIndex = targetIndex;
                                }

                                return;
                            }else {
                                console.log("---- dragIndex"+ listView.dragIndex)
                                console.log("---- index"+ index)
                            }
                        }

                        onExited: {

                        }

                        onDropped: {

                        }
                    }
                }

                spacing: 30
                anchors.left: parent.left
                anchors.leftMargin: 15
            }
        }

        function setUIEvent(bid, cid, event, edata = {}) {
            var eventData = {
                bid: bid,
                cid: cid,
                event: event,
                data: edata ,
            };

            appUIControl.uiEvent(eventData);
        }

    }

}

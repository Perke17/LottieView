import QtQuick 2.12
import QtQuick.Window 2.12

import qt.io.qtws 20.19

import Qt.labs.lottieqt 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Lottie View")

    LottieModel {
        id: lottiefiles
        homeDir: "/Users/freddy/LottieFiles"
    }

    GridView {
        id: lottiegrid
        anchors.fill: parent
        model: lottiefiles
        cellHeight: 130
        cellWidth: 130
        delegate: Rectangle {
            color: "transparent"
            border.color: "#781514"
            border.width: 2
            width: 120; height: 120
            LottieAnimation {
                id: lottie
                anchors.centerIn: parent
                scale: Math.min(parent.height/height, parent.width/width)
                quality: LottieAnimation.HighQuality
                source: display
                autoPlay: false
            }
            MouseArea {
                id: ma
                anchors.fill: parent
                onPressed: {
                    lottie.play()
                }

                onDoubleClicked: {
                    lottiegrid.visible = false
                    lottie4ever.source = lottie.source
                }
            }
        }
    }

    Rectangle {
        anchors.fill: parent
        opacity: lottie4ever.source === "" ? 0 : 1
        Behavior on opacity {
            NumberAnimation { duration: 400; easing.type: Easing.InOutCubic}
        }
        Rectangle {
            anchors.fill: parent
            anchors.margins: 25
            color: "#c0ffee"
            LottieAnimation {
                id: lottie4ever
                anchors.centerIn: parent
                scale: Math.min(parent.height/height, parent.width/width)
                quality: LottieAnimation.HighQuality
                source: ""
                autoPlay: true
                loops: LottieAnimation.Infinite

            }
            Text {
                anchors.bottom: parent.bottom
                text: lottie4ever.source
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    lottiegrid.visible = true
                    lottie4ever.source = ""
                }
                enabled: lottie4ever.source !== ""
            }
        }
    }
}

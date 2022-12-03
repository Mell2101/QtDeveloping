import QtQuick

BorderImage {

    property alias text: _txt.text
    source: "qrc:///new/button/GreenButton.png"
    width: _txt.width+15
    height: _txt.height+12
    signal clicked


    Text {
        id: _txt
        text: "Save button"
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked:parent.clicked()

        onPressed: {
            parent.source = "qrc:///new/button/BlueButton.png"
        }
        onReleased: {
            parent.source = "qrc:///new/button/GreenButton.png"
        }

    }

}

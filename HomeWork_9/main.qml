import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import TaskManeger 1.0

Window{
    id:_win
    visible: true
    width: 640
    height: 480
    title: "Hello world"

    color: "steelblue"

    TaskManager{
        id: _tm
    }

    GridLayout{
        rows: 10
        columns: 10

            TextField{
                id: _txtTask
                Layout.row:0
                Layout.column: 0

                placeholderText: "Enter your task"

                background: Rectangle {
                         implicitWidth: 200
                         implicitHeight: 25

                         radius: 5

                     }

            }

            TextField{
                id:_txtDay
                Layout.row:0
                Layout.column: 1

                placeholderText: "day"

                background: Rectangle {
                         implicitWidth: 40
                         implicitHeight: 25

                         radius: 5

                     }

            }

            TextField{
                id:_txtMoth
                Layout.row:0
                Layout.column: 2

                placeholderText: "Month"

                background: Rectangle {
                         implicitWidth: 50
                         implicitHeight: 25

                         radius: 5

                     }

            }

            TextField{
                id:_txtYear
                Layout.row:0
                Layout.column: 3

                placeholderText: "Year"

                background: Rectangle {
                         implicitWidth: 40
                         implicitHeight: 25

                         radius: 5

                     }

            }

            Text {
                text: qsTr(_tm.progress())
            }

            Rectangle{

                color: _win.color
                Layout.row: 0
                Layout.column:6

                height: 25
                width: 50

                SaveButton{

                    anchors.fill: parent
                    text: "+"
                    onClicked: {
                        _tm.setTreeTask(_txtTask.text)

                    }

                }
            }


            Rectangle{

                color: _win.color
                Layout.row: 0
                Layout.column:7

                height: 25
                width: 80

                SaveButton{

                    anchors.fill: parent
                    text: "Add Task"
                    onClicked: {
                        _tm.setTask(_txtTask.text)
                        _tm.setDate(_txtDay.text, _txtMoth.text, _txtYear.text)
                        _tm.creatTaskTree();
                        _tm.creatTask();


                    }

                }
            }

            Rectangle{

                color: _win.color
                Layout.row: 0
                Layout.column:8

                height: 25
                width: 80

                SaveButton{

                    anchors.fill: parent
                    text: "Save All"
                    onClicked: {
                        _tm.saveAll();
                    }

                }
            }



        }


}

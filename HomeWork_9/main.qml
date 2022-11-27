import QtQuick 2.15
import TaskManeger 1.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15


Window {
    width: 900
    height: 540
    visible: true
    title: qsTr("Hello World")

    TaskManeger{
        id: _taskmaneger
    }

    GridLayout{

        TextField{

            id: _txtTask
            text: "Enter your task!"
            selectionColor: "blue"


        }

        TextEdit{

            readOnly: true
            text: ", complete up to: "

        }

        SpinBox{
            value: 0
            id: _txtDateDay



        }

        SpinBox{
            value: 0
            id: _txtDateMonth
        }

        SpinBox{
            value: 0
            id: _txtDateYear
        }



        TextEdit{

            readOnly: true
            text: ". Current progress:"

        }

        TextField{
            id: _txtProg
            text: "Enter your progress"

        }

        Button{


            onClicked: {
                _taskmaneger.setTask(_txtTask)
                _taskmaneger.setTime(_txtDateDay, _txtDateMonth, _txtDateYear)
                _taskmaneger.setProgress(_txtProg)
                _taskmaneger.creatTask()
            }
        }

    }


}

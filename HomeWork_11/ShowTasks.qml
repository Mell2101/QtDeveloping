import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import TaskManeger 1.0


Window{
    property alias visible:_winTask.visible
    id:_winTask
    width: 640
    height: 480

    TaskManager{
        id: _tm
    }


    TableView{
        model: _tm.getModel()

    }



}

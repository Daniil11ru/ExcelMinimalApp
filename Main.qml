import QtQuick
import QtQuick.Window

// Главное окно приложения
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Excel Minimal App")

    // Код внутри этого блока выполняется после "прогрузки" компонента (в данном случае - главного окна)
    Component.onCompleted: {
        text.text = appcore.readFirstCell("doc.xlsx"); // вызываем нужный метод у appcore
                                                       // и получаем значение первой ячейки
    }

    Text {
        id: text
        text: qsTr("text")
        font.pointSize: 24
        anchors.centerIn: parent
    }
}

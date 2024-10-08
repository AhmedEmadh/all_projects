import QtQuick
import QtQuick.Controls

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Input Checking")

    Column {
        id: column
        width: 120
        height: 75
        anchors.centerIn: parent

        TextField {
            id: textField
            placeholderText: "Enter some text"
        }


        Button {
            id: button
            text: "Enter 1234"
            onClicked: {
                if (textField.text === "1234") {
                    popupText.text = "Correct input";
                } else {
                    popupText.text = "Wrong input";
                }
                myPopup.open();
            }
        }
        Label{
            text: "Created by Ahmed Emad"
            color: "red"
        }
    }

    Popup {
        id: myPopup
        anchors.centerIn: parent
        width: 150
        height: 75
        closePolicy: Popup.CloseOnEscape

        Column {
            anchors.centerIn: parent
            spacing: 10

            Text {
                id: popupText
                text: ""
            }

            Button {
                text: "Close"
                width: 100
                onClicked: {
                    myPopup.close();
                }
            }
        }
    }
}

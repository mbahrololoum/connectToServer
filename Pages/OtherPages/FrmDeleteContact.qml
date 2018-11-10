import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import Company.ServiceDeleteContact 1.0

import "../Component/Button" as MyButtonComponent

Item {
    Component.onCompleted: { flickableOpacity.start(); forceActiveFocus() }

    ServiceDeleteContact{
        id: serviceDeleteContact
        onSignalCheckContactSuccess: {
            busyIndicator.visible = false
            nameTxt.text = name
            familyTxt.text = family
            favirotySw.checked = favority ? true : false
            gender === "Male"   ? maleRadio.checked   = true : maleRadio.checked   = false
            gender === "Female" ? femaleRadio.checked = true : femaleRadio.checked = false

            showColumnLayoutOpacity.start()
            hiddenButtonOpacity.start()
        }
        onSignalFaile: {
            busyIndicator.visible = false
            messageDialog.title = titleMsg
            messageDialog.text  = textMsg
            messageDialog.open()
        }
        onSignalDeleteContactSuccess:{
            busyIndicator.visible = false
            hiddenColumnLayoutOpacity.start()
            showButtonOpacity.start()
            phoneNumberTxt.text = ""
            messageDialog.title = "Delete"
            messageDialog.text  = "Information was Delete successfully"
            messageDialog.open()
        }
    }

    NumberAnimation { id: showColumnLayoutOpacity;   target: columnLayout;   properties: "opacity"; from: 0.0; to: 1.0; duration: 700 }
    NumberAnimation { id: hiddenColumnLayoutOpacity; target: columnLayout;   properties: "opacity"; from: 1.0; to: 0.0; duration: 700 }

    NumberAnimation { id: showButtonOpacity;         target: checkBtn;       properties: "opacity"; from: 0.0; to: 1.0; duration: 700 }
    NumberAnimation { id: hiddenButtonOpacity;       target: checkBtn;       properties: "opacity"; from: 1.0; to: 0.0; duration: 700 }

    NumberAnimation { id: flickableOpacity;          target: flickable;      properties: "opacity"; from: 0.0; to: 1.0; duration: 700 }

    Flickable {
        id: flickable
        anchors.fill: parent
        contentHeight: parent.height + 10
        opacity: 0

        ColumnLayout{
            anchors.centerIn: parent
            spacing: 15

            Label {
                text: "Delete Contact"
                font { family: myStyle.iranSanceFontL; pixelSize: 20 }
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Label {
                text: "Please insert mobile  number for delete contact."
                font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
                Layout.preferredWidth:  parent.width
                Layout.preferredHeight: contentHeight
                wrapMode: Label.WordWrap
                lineHeight: 1
            }

            TextField {
                id: phoneNumberTxt
                placeholderText: qsTr("Phone Number")
                font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                anchors.horizontalCenter: parent.horizontalCenter
                Layout.preferredWidth: controlWidth
                horizontalAlignment: Text.AlignLeft
                validator: RegExpValidator { regExp: /(^(09)[0-9]{9}\\d$)/ }
                inputMethodHints: Qt.ImhDialableCharactersOnly
                focus: true
            }

            MyButtonComponent.CustomeButton {
                id: checkBtn
                buttonText: "Check Contact"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    if(phoneNumberTxt.text.length !== 11)
                    {
                        messageDialog.title = "Error"
                        messageDialog.text  = "Please enter mobile number."
                        messageDialog.open()
                        return
                    }
                    busyIndicator.visible = true
                    serviceDeleteContact.requestCheckContact(phoneNumberTxt.text)
                }
            }

            ColumnLayout{
                id: columnLayout
                spacing: 15
                opacity: 0

                TextField {
                    id: nameTxt
                    placeholderText: qsTr("Name")
                    font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.preferredWidth: controlWidth
                    horizontalAlignment: Text.AlignLeft
                    focus: true
                }

                TextField {
                    id: familyTxt
                    placeholderText: qsTr("Family")
                    font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.preferredWidth: controlWidth
                    horizontalAlignment: Text.AlignLeft
                }

                RowLayout {
                    spacing: 5

                    Label  { text: "Favority" }
                    Switch { id: favirotySw   }
                }

                RowLayout {
                    spacing: 5

                    Label       { text: "gender"                                         }
                    RadioButton { id: femaleRadio; enabled: false; text: qsTr("Female")  }
                    RadioButton { id: maleRadio;   enabled: false; text: qsTr("Male")    }
                }

                RowLayout {
                    spacing: 5

                    MyButtonComponent.CustomeButton {
                        id: myButtonDelete
                        buttonText: "Delete"
                        buttonBackColor: Material.color(Material.Red)
                        width: controlWidth / 2
                        onClicked: { busyIndicator.visible = true; serviceDeleteContact.requestDeleteContact(phoneNumberTxt.text) }
                    }

                    MyButtonComponent.CustomeButton {
                        id: myButtonCancel
                        buttonText: "Cancel"
                        buttonBackColor: Material.color(Material.Green)
                        width: controlWidth / 2
                        onClicked: { hiddenColumnLayoutOpacity.start(); showButtonOpacity.start() }
                    }
                }
            }
        }
    }
}

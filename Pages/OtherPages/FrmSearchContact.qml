import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import Company.ServiceSearchContact 1.0

import "../Componnet/Button" as MyButtonComponnent

Item {

    Component.onCompleted: searchClmOpacity.start()

    property bool animationLastState: false

    ServiceSearchContact{
        id: serviceSearchContact

        onSignalSearchContactSuccess: {
            busyIndicator.visible = false
            nameTxt.text = name
            familyTxt.text = family
            favirotySw.checked = favority ? true : false
            gender === "Male"   ? maleRadio.checked   = true : maleRadio.checked   = false
            gender === "Famele" ? femaleRadio.checked = true : femaleRadio.checked = false

            showContactClmOpacity.start()
            hiddencheckBtnOpacity.start()
            animationLastState = true
        }
        onSignalFaile: {
            busyIndicator.visible = false
            messageDialog.title = "Error"
            messageDialog.text  = "Contact could not exist"
            messageDialog.open()
        }
    }

    NumberAnimation { id: showContactClmOpacity;   target: showContactClm; properties: "opacity"; from: 0.0; to: 1.0; duration: 700 }
    NumberAnimation { id: hiddenContactClmOpacity; target: showContactClm; properties: "opacity"; from: 1.0; to: 0.0; duration: 700 }

    NumberAnimation { id: showCheckBtnOpacity;     target: checkBtn;       properties: "opacity"; from: 0.0; to: 1.0; duration: 700 }
    NumberAnimation { id: hiddencheckBtnOpacity;   target: checkBtn;       properties: "opacity"; from: 1.0; to: 0.0; duration: 700 }

    NumberAnimation { id: searchClmOpacity;        target: searchClm;      properties: "opacity"; from: 0.0; to: 1.0; duration: 700 }

    Flickable {
        id: searchClm
        anchors.fill: parent
        contentHeight: parent.height + 10
        opacity: 0

        ColumnLayout{
            anchors.centerIn: parent
            spacing: 15


            Label {
                id: titleWelcom
                text: "Search Contact"
                font { family: myStyle.iranSanceFontL; pixelSize: 20 }
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Label {
                text: "Please insert mobile  number for\nsearch contact."
                font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignLeft
            }

            TextField {
                id: phoneNumberTxt
                placeholderText: qsTr("Phone Number")
                font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                anchors.horizontalCenter: parent.horizontalCenter
                Layout.preferredWidth: controlWidth
                height: 45
                horizontalAlignment: Text.AlignLeft
                validator: RegExpValidator { regExp: /(^(09)[0-9]{9}\\d$)/ }
                inputMethodHints: Qt.ImhDialableCharactersOnly
                focus: true
                onTextChanged: if(phoneNumberTxt.length !== 11 && animationLastState) { hiddenContactClmOpacity.start(); showCheckBtnOpacity.start(); animationLastState = false }
            }

            MyButtonComponnent.CustomeButton {
                id: checkBtn
                buttonText: "Search"
                enabled: true
                buttonFontSize: 14
                anchors.horizontalCenter: parent.horizontalCenter
                width: controlWidth
                buttonHeight: 35
                onClicked: {
                    if(phoneNumberTxt.text.length !== 11)
                    {
                        messageDialog.title = "Error"
                        messageDialog.text  = "Please enter mobile number."
                        messageDialog.open()
                        return
                    }
                    busyIndicator.visible = true
                    serviceSearchContact.requestSearchContact(phoneNumberTxt.text)
                }
            }

            ColumnLayout{
                id: showContactClm
                spacing: 15
                opacity: 0

                TextField {
                    id: nameTxt
                    placeholderText: qsTr("Name")
                    font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.preferredWidth: controlWidth
                    height: 45
                    horizontalAlignment: Text.AlignLeft
                    focus: true
                }

                TextField {
                    id: familyTxt
                    placeholderText: qsTr("Family")
                    font { family: myStyle.iranSanceFontL; pixelSize: 14 }
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.preferredWidth: controlWidth
                    height: 45
                    horizontalAlignment: Text.AlignLeft
                    focus: true
                }

                RowLayout {
                    spacing: 5

                    Label  { text: "Favority" }
                    Switch { id: favirotySw;  }
                }

                RowLayout {
                    spacing: 5

                    Label       { text: "gender"                                         }
                    RadioButton { id: femaleRadio; enabled: false; text: qsTr("female")  }
                    RadioButton { id: maleRadio;   enabled: false; text: qsTr("Male")    }
                }
            }
        }
    }
}

// Copyright (c) Daniel Gakwaya.
// SPDX-License-Identifier: MIT

/*
    Property bindings:
        . Reference: https://doc.qt.io/qt-6/qtqml-syntax-propertybinding.html
        . Introduce property bindings.
        . Show that changing the binding with a static value breaks the binding.
        . Show how to update the binding with the Qt.binding thing
        . Show the this keyword and that in applies to the element that receives the binding
            . In this case: redRectId
  */

import QtQuick

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Property Binding Demo")

    Rectangle {
        id: redRectId
        width: 50
        //height: width * 1.5

        //height: parent.height / 2

        //height: Math.min(parent.width, parent.height)
        //height: parent.height > 100 ? parent.height : parent.height/2
        //height: {
        //    if (parent.height > 100)
        //        return parent.height
        //    else
        //        return parent.height / 2
        //}
        height: someMethodThatReturnsHeight()

        color: "red"
    }

    Rectangle {
        id: blueRectId
        color: "blue"
        width: 100
        height: 100
        anchors.bottom: parent.bottom

        MouseArea {
            anchors.fill: parent
            onClicked: {
                redRectId.width = redRectId.width + 10
            }
        }
    }

    Rectangle {
        id: greenRectId
        color: "green"
        width: 100
        height: 100
        anchors.bottom: parent.bottom
        anchors.left: blueRectId.right

        MouseArea {
            anchors.fill: parent
            //Change the relationship between redRectId.width and redRectId.height
            onClicked: {
                //redRectId.height = 100 // Doesn't work
                //redRectId.height = redRectId.width * 1.5 // Doesn't work either

                 redRectId.height = Qt.binding(function() {
                     return redRectId.width * 2
                 })

                //redRectId.height = Qt.binding(function(){
                //        return this.width * 2
                //})


            }
        }
    }
}

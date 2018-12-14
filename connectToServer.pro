QT += qml quick sql svg location positioning

CONFIG += c++11

SOURCES += main.cpp \
    Model/Entity/EntityContactList.cpp \
    Model/Model/ModelContactList.cpp \
    Model/Model/qobjectlistmodel.cpp \
    Model/da/JsonNetworkHandler.cpp \
    Model/Service/ServiceLogin.cpp \
    Model/Service/ServiceNewContact.cpp \
    Model/Service/ServiceDeleteContact.cpp \
    Model/Service/ServiceSearchContact.cpp \
    Model/Service/ServiceContactList.cpp \
    Model/Service/ServiceMap.cpp \
    Model/Model/ModelMap.cpp \
    Model/Entity/EntityMap.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(android-openssl.pri)

HEADERS += \
     Model/Entity/EntityContactList.h \
    Model/Model/ModelContactList.h \
    Model/Model/qquicklist.h \
    Model/Model/qobjectlistmodel.h \
    Model/da/JsonNetworkHandler.h \
    Model/Service/ServiceLogin.h \
    Model/Service/ServiceNewContact.h \
    Model/Service/ServiceDeleteContact.h \
    Model/Service/ServiceSearchContact.h \
    Model/Service/ServiceContactList.h \
    Model/Service/ServiceMap.h \
    Model/Model/ModelMap.h \
    Model/Entity/EntityMap.h

DISTFILES += \
    prebuilt/armeabi-v7a/libcrypto.so \
    prebuilt/armeabi-v7a/libssl.so \
    prebuilt/x86/libcrypto.so \
    prebuilt/x86/libssl.so \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android


























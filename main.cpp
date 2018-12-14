#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "Model/da/JsonNetworkHandler.h"
#include "Model/Service/ServiceLogin.h"
#include "Model/Service/ServiceNewContact.h"
#include "Model/Service/ServiceDeleteContact.h"
#include "Model/Service/ServiceSearchContact.h"
#include "Model/Service/ServiceContactList.h"
#include "Model/Service/ServiceMap.h"

#include "Model/Entity/EntityMap.h"
#include "Model/Model/ModelMap.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<ServiceLogin>("Company.ServiceLogin", 1, 0, "ServiceLogin");
    qmlRegisterType<ServiceNewContact>("Company.ServiceNewContact", 1, 0, "ServiceNewContact");
    qmlRegisterType<ServiceDeleteContact>("Company.ServiceDeleteContact", 1, 0, "ServiceDeleteContact");
    qmlRegisterType<ServiceSearchContact>("Company.ServiceSearchContact", 1, 0, "ServiceSearchContact");
    qmlRegisterType<ServiceContactList>("Company.ServiceContactList", 1, 0, "ServiceContactList");
    qmlRegisterType<ServiceMap>("Company.ServiceMap", 1, 0, "ServiceMap");


    qmlRegisterType<EntityContactList>("EntityContactList", 1, 0, "EntityContactList");

    qRegisterMetaType<ModelContactList*>("ModelContactList*");
    qRegisterMetaType<ModelMap*>("ModelMap*"); // For Map


    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

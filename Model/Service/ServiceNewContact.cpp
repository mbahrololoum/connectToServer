#include "ServiceNewContact.h"

ServiceNewContact::ServiceNewContact(QObject *parent) : QObject(parent)
{
    o_JsonNetworkHandler = new JsonNetworkHandler();

    connect(o_JsonNetworkHandler, SIGNAL(signalCreateNewContact(QJsonObject*)), this, SLOT(responceCreateNewContact(QJsonObject*)));
}

ServiceNewContact::~ServiceNewContact()
{
    delete o_JsonNetworkHandler;
}

void ServiceNewContact::requestCreateNewContact(const QString& name, const QString& family, const QString& phoneNumber, const int& favority, const QString& gender)
{
    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "createNewContact");

    QJsonObject qJsonObject2;
    qJsonObject2.insert("name", name);
    qJsonObject2.insert("family", family);
    qJsonObject2.insert("phoneNumber", phoneNumber);
    qJsonObject2.insert("favority", favority);
    qJsonObject2.insert("gender", gender);
    qJsonObject.insert("data", qJsonObject2);

    QJsonDocument qJsonDocument(qJsonObject);
    QString address = "/createNewContact";

    o_JsonNetworkHandler->sendRequest(qJsonDocument, address);
}

void ServiceNewContact::responceCreateNewContact(QJsonObject *answer)
{
    QJsonObject result = (*answer);

    if(result["status"].toBool())
        emit signalNewContactSuccess();
    else
        emit signalNewContactFaile(result["titleMsg"].toString(), result["textMsg"].toString());
}

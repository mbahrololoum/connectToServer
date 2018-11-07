#include "ServiceSearchContact.h"

ServiceSearchContact::ServiceSearchContact(QObject *parent) : QObject(parent)
{
    o_JsonNetworkHandler = new JsonNetworkHandler();
    connect(o_JsonNetworkHandler, SIGNAL(signalSearchContact(QJsonObject*)), this, SLOT(responceSearchContact(QJsonObject*)));
}

ServiceSearchContact::~ServiceSearchContact()
{
    delete o_JsonNetworkHandler;
}

void ServiceSearchContact::requestSearchContact(const QString &phoneNumber)
{
    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "searchContact");

    QJsonObject qJsonObject2;
    qJsonObject2.insert("phoneNumber", phoneNumber);
    qJsonObject.insert("data", qJsonObject2);

    QJsonDocument qJsonDocument(qJsonObject);
    QString address = "/checkContact";

    o_JsonNetworkHandler->sendRequest(qJsonDocument, address);
}

void ServiceSearchContact::responceSearchContact(QJsonObject *answer)
{
    QJsonObject result = (*answer);

    if(result["status"].toBool())
    {
        result = result["data"].toObject();
        emit signalSearchContactSuccess(result["name"].toString(), result["family"].toString(), result["favority"].toInt(), result["gender"].toString());
    }
    else
        emit signalFaile(result["titleMsg"].toString(), result["textMsg"].toString());
}

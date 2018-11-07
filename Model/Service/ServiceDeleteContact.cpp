#include "ServiceDeleteContact.h"

ServiceDeleteContact::ServiceDeleteContact(QObject *parent) : QObject(parent)
{
    o_JsonNetworkHandler = new JsonNetworkHandler();
    connect(o_JsonNetworkHandler, SIGNAL(signalCheckContact(QJsonObject*)), this, SLOT(responceCheckContact(QJsonObject*)));
    connect(o_JsonNetworkHandler, SIGNAL(signalDeleteContact(QJsonObject*)), this, SLOT(responceDeleteContact(QJsonObject*)));
    connect(o_JsonNetworkHandler, SIGNAL(signalDeleteContactList(QJsonObject*)), this, SLOT(responceDeleteContactList(QJsonObject*)));

}

ServiceDeleteContact::~ServiceDeleteContact()
{
    delete o_JsonNetworkHandler;
}

void ServiceDeleteContact::requestCheckContact(const QString &phoneNumber)
{
    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "checkContact");

    QJsonObject qJsonObject2;
    qJsonObject2.insert("phoneNumber", phoneNumber);
    qJsonObject.insert("data", qJsonObject2);

    QJsonDocument qJsonDocument(qJsonObject);
    QString address = "/checkContact";

    o_JsonNetworkHandler->sendRequest(qJsonDocument, address);
}

void ServiceDeleteContact::responceCheckContact(QJsonObject *answer)
{
    QJsonObject result = (*answer);

    if(result["status"].toBool())
    {
        //qDebug() << "result[data].toObject(); " << result["data"].toObject()["name"].toString();
        result = result["data"].toObject();
        emit signalCheckContactSuccess(result["name"].toString(), result["family"].toString(), result["favority"].toInt(), result["gender"].toString());
    }
    else
        emit signalFaile(result["titleMsg"].toString(), result["textMsg"].toString());
}

void ServiceDeleteContact::requestDeleteContact(const QString &phoneNumber)
{
    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "deleteContact");

    QJsonObject qJsonObject2;
    qJsonObject2.insert("phoneNumber", phoneNumber);
    qJsonObject.insert("data", qJsonObject2);

    QJsonDocument qJsonDocument(qJsonObject);
    QString address = "/deleteContact";

    o_JsonNetworkHandler->sendRequest(qJsonDocument, address);
}

void ServiceDeleteContact::responceDeleteContact(QJsonObject *answer)
{
    QJsonObject result = (*answer);

    if(result["status"].toBool())
    {
        result = result["data"].toObject();
        emit signalDeleteContactSuccess();
    }
    else
        emit signalFaile(result["titleMsg"].toString(), result["textMsg"].toString());
}


void ServiceDeleteContact::requestDeleteContactList(const QString &phoneNumbers)
{
    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "deleteContactList");

    QJsonObject qJsonObject2;
    qJsonObject2.insert("phoneNumber", phoneNumbers);
    qJsonObject.insert("data", qJsonObject2);

    QJsonDocument qJsonDocument(qJsonObject);
    QString address = "/deleteContactList";

    o_JsonNetworkHandler->sendRequest(qJsonDocument, address);
}

void ServiceDeleteContact::responceDeleteContactList(QJsonObject *answer)
{
    QJsonObject result = (*answer);

    if(result["status"].toBool())
    {
        result = result["data"].toObject();
        emit signalDeleteContactSuccess();
    }
    else
        emit signalFaile(result["titleMsg"].toString(), result["textMsg"].toString());
}

#include "ServiceLogin.h"

ServiceLogin::ServiceLogin(QObject *parent) : QObject(parent)
{
    o_JsonNetworkHandler = new JsonNetworkHandler();
    connect(o_JsonNetworkHandler, SIGNAL(signalLogin(QJsonObject*)), this, SLOT(responceLogin(QJsonObject*)));
}

ServiceLogin::~ServiceLogin()
{
    delete o_JsonNetworkHandler;
}

void ServiceLogin::requestLogin(const QString& username, const QString& password)
{
    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "Login");

    QJsonObject qJsonObject2;
    qJsonObject2.insert("username", username);
    qJsonObject2.insert("password", password);
    qJsonObject.insert("data", qJsonObject2);

    QJsonDocument qJsonDocument(qJsonObject);
    QString address = "/login";

    o_JsonNetworkHandler->sendRequest(qJsonDocument, address);
}

void ServiceLogin::responceLogin(QJsonObject *answer)
{
    QJsonObject result = (*answer);

    if(result["status"].toBool())
    {
        QJsonObject res = result["data"].toObject();
        emit signalLoginSuccess(res["name"].toString(), res["family"].toString());
    }
    else
        emit signalLoginFaile(result["titleMsg"].toString(), result["textMsg"].toString());
}

void ServiceLogin::getSetting()
{
    setting.beginGroup("remmember");
    emit signalGetSetting(setting.value("lastState").toBool(), setting.value("username").toString(), setting.value("password").toString());
    setting.endGroup();
}

void ServiceLogin::setSetting(const bool& state, const QString& username, const QString& password)
{
    setting.beginGroup("remmember");
    setting.setValue("lastState", state);
    setting.setValue("username", state ? username : "");
    setting.setValue("password", state ? password : "");
    setting.endGroup();
}


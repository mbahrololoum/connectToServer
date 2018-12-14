#include "ServiceMap.h"

ServiceMap::ServiceMap(QObject *parent) : QObject(parent)
{
    //Create model
    m_modelMap = new ModelMap();

    //Create connection
    o_JsonNetworkHandler = new JsonNetworkHandler();
    connect(o_JsonNetworkHandler, SIGNAL(signalMap(QJsonObject*)), this, SLOT(response(QJsonObject*)));
}

ServiceMap::~ServiceMap()
{
    delete m_modelMap;
    delete o_JsonNetworkHandler;
}

void ServiceMap::request()
{
    m_modelMap->removeData();

    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "map");

    QJsonDocument qJsonDocument(qJsonObject);
    QString  address = "/maps";

    o_JsonNetworkHandler->sendRequest(qJsonDocument, address);
}

void ServiceMap::response(QJsonObject *answer)
{
    emit sigSuccessfullyMapResponce();
    qDebug() << "\n\n\n\n\n\n\n\n\n  =>        " << (*answer) ;

    QJsonObject result = (*answer);
    QJsonArray res = result["data"].toArray();

    foreach (const QJsonValue& value, res) {
        QJsonObject obj = value.toObject();
        m_modelMap->addData(EntityMap(obj["id"].toInt(), obj["title"].toString(), obj["latitude"].toString(), obj["longitude"].toString()));
    }
}

#include "ServiceContactList.h"

ServiceContactList::ServiceContactList(QObject *parent) : QObject(parent)
{
    m_modelContactList = new ModelContactList();

    //Create connection
    o_JsonNetworkHandler = new JsonNetworkHandler();
    connect(o_JsonNetworkHandler, SIGNAL(signalContactList(QJsonObject*)), this, SLOT(responseContactList(QJsonObject*)));
}

ServiceContactList::~ServiceContactList()
{
    delete m_modelContactList;
    delete o_JsonNetworkHandler;
}

void ServiceContactList::requestContactList()
{
    QJsonObject qJsonObject;
    qJsonObject.insert("functionName", "contactList");

    QJsonDocument qJsonDocument(qJsonObject);
    QString address = "/contactList";

    m_modelContactList->removeAll();
    o_JsonNetworkHandler->sendRequest(qJsonDocument,address);
}

void ServiceContactList::responseContactList(QJsonObject *answer)
{
    QJsonObject result = (*answer);

    if(result["status"].toBool())
    {
        QJsonArray res = result["data"].toArray();

        foreach (const QJsonValue & value, res) {
            QJsonObject obj = value.toObject();
            m_modelContactList->append(obj["name"].toString(), obj["family"].toString(), obj["phoneNumber"].toString(), obj["favority"].toBool(), obj["gender"].toString());
        }
    }
    else
    {
        qDebug() << "\n \n \n \n \n \n \n \n \n FALSE => ";

        emit signalFaile(result["titleMsg"].toString(), result["textMsg"].toString());
    }
}

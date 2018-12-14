#include "JsonNetworkHandler.h"
#include <QtNetwork/QSslConfiguration>

JsonNetworkHandler::JsonNetworkHandler()
{
    networkManager = new QNetworkAccessManager();
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleResponse(QNetworkReply*)));
}

void JsonNetworkHandler::sendRequest(const QJsonDocument &json, const QString &address)
{
    QUrl* url  = new QUrl(serverUrl + address);

    QByteArray qByteArray;
    QString strJson(json.toJson(QJsonDocument::Compact));
    qByteArray.append(strJson);

    // no need to verify ssl type
    QNetworkRequest request;
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1SslV3);   //TlsV1SslV3
    request.setSslConfiguration(config);

    // no need to verify ssl type
    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    QSslConfiguration::setDefaultConfiguration(conf);
    request.setSslConfiguration(conf);


    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(*url);

    qDebug() << "request  " << qByteArray;
    networkManager->post(request,qByteArray);
}

void JsonNetworkHandler::handleResponse(QNetworkReply *res)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(res->readAll());
    QJsonObject jsonObject = jsonResponse.object();

    if(jsonObject["status"].toBool())
        checkFaunctionName(jsonObject);
    else
        emit signalServerError();

    res->deleteLater();
}

void JsonNetworkHandler::checkFaunctionName(QJsonObject qJsonObject)
{
    if(qJsonObject["functionName"].toString() == "Login")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalLogin(&result);
    }
    else if(qJsonObject["functionName"].toString() == "createNewContact")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalCreateNewContact(&result);
    }
    else if(qJsonObject["functionName"].toString() == "checkContact")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalCheckContact(&result);
    }
    else if(qJsonObject["functionName"].toString() == "deleteContact")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalDeleteContact(&result);
    }
    else if(qJsonObject["functionName"].toString() == "searchContact")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalSearchContact(&result);
    }
    else if(qJsonObject["functionName"].toString() == "contactList")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalContactList(&result);
    }
    else if(qJsonObject["functionName"].toString() == "deleteContactList")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalDeleteContactList(&result);
    }
    else if(qJsonObject["functionName"].toString() == "map")
    {
        QJsonObject result = qJsonObject["result"].toObject();
        emit signalMap(&result);
    }
}






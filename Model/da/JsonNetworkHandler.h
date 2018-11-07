#ifndef JsonNetworkHandler_H
#define JsonNetworkHandler_H

#define serverUrl "http://localhost:3003/service/"

#include <QNetworkAccessManager>
#include <QSslConfiguration>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QUrl>

class  JsonNetworkHandler : public QObject
{
    Q_OBJECT

public:

    JsonNetworkHandler();

    void sendRequest(const QJsonDocument & json,const QString &address);

public slots:

signals:

    void signalServerError();

    void signalLogin(QJsonObject* answer);

    void signalCreateNewContact(QJsonObject* answer);

    void signalCheckContact(QJsonObject* answer);

    void signalDeleteContact(QJsonObject* answer);

    void signalSearchContact(QJsonObject* answer);

    void signalContactList(QJsonObject* answer);

    void signalDeleteContactList(QJsonObject* answer);


private slots:

    void handleResponse(QNetworkReply *res);

    void checkFaunctionName(QJsonObject qJsonObject);

private:

    QNetworkAccessManager* networkManager;
};

#endif //JsonNetworkHandler_H

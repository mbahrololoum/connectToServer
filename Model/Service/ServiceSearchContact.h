#ifndef SERVICESEARCHCONTACT_H
#define SERVICESEARCHCONTACT_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>

#include "Model/da/JsonNetworkHandler.h"

class ServiceSearchContact : public QObject
{
    Q_OBJECT

    JsonNetworkHandler* o_JsonNetworkHandler;

public:

    explicit ServiceSearchContact(QObject *parent = nullptr);

    ~ServiceSearchContact();

signals:

    void signalSearchContactSuccess(const QString& name, const QString& family, const int& favority, const QString& gender);

    void signalFaile(const QString& titleMsg, const QString& textMsg);

public slots:

    void requestSearchContact(const QString &phoneNumber);

    void responceSearchContact(QJsonObject *answer);

};

#endif // SERVICESEARCHCONTACT_H

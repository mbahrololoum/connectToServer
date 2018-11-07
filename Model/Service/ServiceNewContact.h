#ifndef SERVICENEWCONTACT_H
#define SERVICENEWCONTACT_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>

#include "Model/da/JsonNetworkHandler.h"

class ServiceNewContact : public QObject
{
    Q_OBJECT

    JsonNetworkHandler* o_JsonNetworkHandler;

public:

    explicit ServiceNewContact(QObject *parent = nullptr);

    ~ServiceNewContact();

signals:

    void signalNewContactSuccess();

    void signalNewContactFaile(const QString& titleMsg, const QString& textMsg);

public slots:

    void requestCreateNewContact(const QString& name, const QString& family, const QString& phoneNumber, const int& favority, const QString& gender);

    void responceCreateNewContact(QJsonObject *answer);

};

#endif // SERVICENEWCONTACT_H

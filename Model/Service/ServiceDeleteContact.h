#ifndef SERVICEDELETECONTACT_H
#define SERVICEDELETECONTACT_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>

#include "Model/da/JsonNetworkHandler.h"

class ServiceDeleteContact : public QObject
{
    Q_OBJECT

    JsonNetworkHandler* o_JsonNetworkHandler;

public:

    explicit ServiceDeleteContact(QObject *parent = nullptr);

    ~ServiceDeleteContact();

signals:

    void signalCheckContactSuccess(const QString& name, const QString& family, const int& favority, const QString& gender);

    void signalDeleteContactSuccess();

    void signalFaile(const QString& titleMsg, const QString& textMsg);

public slots:

    void requestCheckContact(const QString &phoneNumber);

    void responceCheckContact(QJsonObject *answer);

    void requestDeleteContact(const QString &phoneNumber);

    void responceDeleteContact(QJsonObject *answer);

    void requestDeleteContactList(const QString &phoneNumbers);

    void responceDeleteContactList(QJsonObject *answer);


};

#endif // SERVICEDELETECONTACT_H

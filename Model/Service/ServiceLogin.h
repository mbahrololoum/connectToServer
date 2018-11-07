#ifndef SERVICELOGIN_H
#define SERVICELOGIN_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>

#include "Model/da/JsonNetworkHandler.h"

class ServiceLogin : public QObject
{
    Q_OBJECT

    JsonNetworkHandler* o_JsonNetworkHandler;

public:

    explicit ServiceLogin(QObject *parent = nullptr);

    ~ServiceLogin();

    Q_INVOKABLE void getSetting();

    Q_INVOKABLE void setSetting(const bool &state, const QString &username, const QString &password);

signals:

    void signalLoginSuccess(const QString& name, const QString& family);

    void signalLoginFaile(const QString& titleMsg, const QString& textMsg);

    void signalGetSetting(const bool& lastState, const QString& username, const QString& password);

public slots:

    void requestLogin(const QString &username, const QString &password);

    void responceLogin(QJsonObject *answer);

private:

    QSettings setting;
};

#endif // SERVICELOGIN_H

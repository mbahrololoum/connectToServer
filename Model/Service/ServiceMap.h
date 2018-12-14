#ifndef SERVICEMAP_H
#define SERVICEMAP_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "Model/da/JsonNetworkHandler.h"
#include "Model/Model/ModelMap.h"
#include "Model/Entity/EntityMap.h"

class ServiceMap : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ModelMap* modelMap READ modelMap WRITE setModelMap NOTIFY ModelMapChanged)

    JsonNetworkHandler* o_JsonNetworkHandler;

    ModelMap* m_modelMap;

public:

    explicit ServiceMap(QObject *parent = nullptr);

    ~ServiceMap();

    ModelMap* modelMap() const
    {
        return m_modelMap;
    }

    QString functionName;

signals:

    void rejectServer();

    void sigGetResponce();

    void signalTimeOut();

    void sigEmptySearchNearBy();

    void sigSuccessfullyMapResponce();

    void ModelMapChanged(ModelMap* modelMap);

public slots:

    void request();

    void response(QJsonObject *answer);

    void setModelMap(ModelMap* modelMap)
    {
        if (m_modelMap == modelMap)
            return;

        m_modelMap = modelMap;
        emit ModelMapChanged(m_modelMap);
    }
};

#endif // SERVICEMAP_H

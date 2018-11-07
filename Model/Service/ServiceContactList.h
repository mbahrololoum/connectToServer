#ifndef SERVICECONTACTLIST_H
#define SERVICECONTACTLIST_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "Model/da/JsonNetworkHandler.h"
#include "Model/Model/ModelContactList.h"

class ServiceContactList : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ModelContactList* modelContactList READ modelContactList WRITE setModelContactList NOTIFY modelContactListChanged)

    ModelContactList* m_modelContactList;

    JsonNetworkHandler* o_JsonNetworkHandler;

public:

    explicit ServiceContactList(QObject *parent = nullptr);

    ~ServiceContactList();

    ModelContactList* modelContactList() const
    {
        return m_modelContactList;
    }

signals:

    void modelContactListChanged(ModelContactList* modelContactList);

    void signalFaile(const QString& titleMsg, const QString& textMsg);

public slots:

    void requestContactList();

    void responseContactList(QJsonObject *answer);

    void setModelContactList(ModelContactList* modelContactList)
    {
        if (m_modelContactList == modelContactList)
            return;

        m_modelContactList = modelContactList;
        emit modelContactListChanged(m_modelContactList);
    }
};

#endif // SERVICECONTACTLIST_H

#ifndef MODELMAP_H
#define MODELMAP_H

#include <QObject>
#include <QAbstractListModel>

#include "../Entity/EntityMap.h"

class ModelMap : public QAbstractListModel
{
    Q_OBJECT

public:

    enum itemRoles {
        myId = Qt::UserRole + 1,
        myTitle,
        mylatitude,
        mylongitude,
    };

    ModelMap(QObject *parent = 0);

    void addData(const EntityMap &data);

    void removeData();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

signals:

    void ModelMapChanged();

protected:

    QHash<int, QByteArray> roleNames() const;

private:

    QList<EntityMap> m_data;
};

#endif // MODELMAP_H

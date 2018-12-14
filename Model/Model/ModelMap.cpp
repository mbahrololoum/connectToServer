#include "ModelMap.h"

ModelMap::ModelMap(QObject *parent) : QAbstractListModel(parent)
{

}

void ModelMap::addData(const EntityMap &data)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data << data;
    endInsertRows();
}

void ModelMap::removeData()
{
    m_data.clear();
}

int ModelMap::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant ModelMap::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= m_data.count())
        return QVariant();

    const EntityMap &data = m_data[index.row()];

    if (role == myId)
        return data.id();
    else if (role == myTitle)
        return data.title();
    else if (role == mylatitude)
        return data.latitude();
    else if (role == mylongitude)
        return data.longitude();

    return QVariant();
}

QHash<int, QByteArray> ModelMap::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[myId]        = "id";
    roles[myTitle]     = "title";
    roles[mylatitude]  = "latitude";
    roles[mylongitude] = "longitude";

    return roles;
}

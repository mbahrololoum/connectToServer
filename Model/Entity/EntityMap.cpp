#include "EntityMap.h"

EntityMap::EntityMap(const int &id, const QString &title, const QString &latitude, const QString &longitude)
    : m_id(id), m_title(title), m_latitude(latitude), m_longitude(longitude)
{

}

int EntityMap::id() const
{
    return m_id;
}

QString EntityMap::title() const
{
    return m_title;
}

QString EntityMap::latitude() const
{
    return m_latitude;
}

QString EntityMap::longitude() const
{
    return m_longitude;
}

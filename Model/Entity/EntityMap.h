#ifndef ENTITYMAP_H
#define ENTITYMAP_H

#include <QObject>

class EntityMap
{

public:

    EntityMap(const int &id, const QString &title, const QString &latitude, const QString &longitude);

    int id() const;

    QString title() const;

    QString latitude() const;

    QString longitude() const;

private:

    int m_id;

    QString m_title;

    QString m_latitude;

    QString m_longitude;
};

#endif // ENTITYMAP_H

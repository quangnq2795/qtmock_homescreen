#ifndef EVENTDATA_H
#define EVENTDATA_H

#include <QObject>
#include <QString>
#include <QVariant>

class EventData
{
public:
    EventData(QString bid, QString cid, QString event, QVariant data);

    QString bid() const;
    QString cid() const;
    QString event() const;
    QVariant data() const;

private:
    QString m_bid;
    QString m_cid;
    QString m_event;
    QVariant m_data;
};

#endif // EVENTDATA_H

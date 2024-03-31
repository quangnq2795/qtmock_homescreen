#include "eventdata.h"

EventData::EventData(QString bid, QString cid, QString event, QVariant data): m_bid(bid), m_cid(cid), m_event(event), m_data(data)
{
}

QString EventData::bid() const
{
    return m_bid;
}


QString EventData::cid() const
{
    return m_cid;
}


QString EventData::event() const
{
    return m_event;
}


QVariant EventData::data() const
{
    return m_data;
}


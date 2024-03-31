#ifndef IUIBAR_H
#define IUIBAR_H

#include <QObject>
#include <QVariant>
#include <QMap>

#include <functional>

#include "icomponent.h"
#include "eventdata.h"

class IUIBar : public QObject
{
    Q_OBJECT
public:

    IUIBar(QObject* parent = nullptr);

    void emitEvent(const EventData& eData);
    void addComponent(IComponent* item);

signals:
    void uiEvent(const EventData&);

public slots:
    virtual void handleUIEvent(const EventData& eData);

private:
     QList<IComponent*> componentList;
};

#endif // IUIBAR_H

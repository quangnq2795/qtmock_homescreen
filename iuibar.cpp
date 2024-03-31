#include "iuibar.h"
#include <QDebug>

IUIBar::IUIBar(QObject* parent) : QObject(parent)
{
    connect(this, &IUIBar::uiEvent, this, &IUIBar::handleUIEvent);
}

void IUIBar::emitEvent(const EventData& eData)
{
    emit uiEvent(eData);
}

void IUIBar::handleUIEvent(const EventData& eData)
{
    QString cId   = eData.cid();
    QString event = eData.event();
    QVariant data = eData.data();

    for (IComponent* component : componentList) {
        if (component->id() == cId) {
            component->handleEvent(event, data);
            return;
        }
    }
}

void IUIBar::addComponent(IComponent* item)
{
    for (IComponent* widget : componentList) {
        if (widget->id() == item->id()) {
            return;
        }
    }

    componentList.append(item);
}

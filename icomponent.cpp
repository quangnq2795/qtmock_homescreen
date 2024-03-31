#include "icomponent.h"


void IComponent::handleEvent(QString event, QVariant data)
{
    auto it = eventHandlers.find(event);
    if (it != eventHandlers.end()) {
        it.value()(data);
    } else {

    }
}

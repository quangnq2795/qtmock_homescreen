#include "widgetbar.h"
#include "mediawidget.h"

WidgetBar::WidgetBar(QObject* parent) : IUIBar(parent)
{
    IComponent* mediaWidget = new MediaWidget();
    addComponent(mediaWidget);
}


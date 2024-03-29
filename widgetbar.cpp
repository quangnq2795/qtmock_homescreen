#include "widgetbar.h"
#include "mediawidget.h"

WidgetBar::WidgetBar(QObject* parent) : QObject(parent)
{
    IWidget* mediaWidget = new MediaWidget();
    addWidgetHandler(mediaWidget);
}

void WidgetBar::handleWidgetEvent(QString widgetId, QString event, QVariant data)
{
    for (IWidget* widget : widgetList) {
        if (widget->id() == widgetId) {
            widget->handleEvent(event, data);
            return;
        }
    }
}

void WidgetBar::addWidgetHandler(IWidget* item)
{
    for (IWidget* widget : widgetList) {
        if (widget->id() == item->id()) {
            return;
        }
    }

    widgetList.append(item);
}

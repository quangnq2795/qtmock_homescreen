#ifndef WIDGETBAR_H
#define WIDGETBAR_H

#include <QObject>
#include <QList>

#include "iuibar.h"
#include "icomponent.h"

class WidgetBar : public IUIBar
{
    Q_OBJECT
public:
    WidgetBar(QObject* parent = nullptr);
};

#endif // WIDGETBAR_H

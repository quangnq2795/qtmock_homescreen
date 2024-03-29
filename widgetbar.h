#ifndef WIDGETBAR_H
#define WIDGETBAR_H

#include <QObject>
#include <QList>

#include "iwidget.h"

class WidgetBar : public QObject
{
    Q_OBJECT
public:
    WidgetBar(QObject* parent = nullptr);

public slots:
    void handleWidgetEvent(QString widgetId, QString event, QVariant  data);

private:

    void addWidgetHandler(IWidget* item);

private:
     QList<IWidget*> widgetList;
};

#endif // WIDGETBAR_H

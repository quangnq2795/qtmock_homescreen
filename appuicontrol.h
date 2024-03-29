#ifndef APPUICONTROL_H
#define APPUICONTROL_H

#include <QObject>

#include "applicationbar.h"
#include "widgetbar.h"
#include "iappuicontrolreceiver.h"

class AppUIControl: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isHomeScreenAppVisible READ getHomeScreenAppVisibleProperty NOTIFY homeScreenAppVisibleChanged)

public:
    AppUIControl(ApplicationBar* appBar, WidgetBar *widgetBar, QObject* parent = nullptr);

    Q_INVOKABLE void uiEventApplicationClicked(int index);
    Q_INVOKABLE void uiEventWidgetUpdated(QString widgetId, QString event, QVariant data);

public slots:
    void handleHomeScreenAppVisibleChanged(bool val);

signals:
    void applicationClicked(int index);
    void widgetUpdated(QString widgetId, QString event, QVariant data);
    void homeScreenAppVisibleChanged();

private:
    bool getHomeScreenAppVisibleProperty() const;

private:
    bool    m_appVisible;
    ApplicationBar* m_appBar;
    WidgetBar * m_widgetBar;

    IAppUIControlReceiver* m_UIControlReceiver;
};

#endif // APPUICONTROL_H

#include "appuicontrol.h"
#include "appmanageruicontrol.h"

AppUIControl::AppUIControl(ApplicationBar* appBar, WidgetBar *widgetBar, QObject* parent): m_appBar(appBar), m_widgetBar(widgetBar)
{
    qDebug() << "HomeScreen startup";

    m_UIControlReceiver = new IAppUIControlReceiver();

    connect(m_UIControlReceiver, &IAppUIControlReceiver::appVisibleChanged, this, &AppUIControl::handleHomeScreenAppVisibleChanged);

    connect(this, SIGNAL(applicationClicked(int)), appBar, SLOT(handleRunApplication(int)));
    connect(this, SIGNAL(widgetUpdated(QString, QString, QVariant)), widgetBar, SLOT(handleWidgetEvent(QString, QString, QVariant)));

    m_appVisible = AppManagerUIControl::getInstance().getAppVisible("homescreen");

}

void AppUIControl::uiEventApplicationClicked(int index)
{
    emit applicationClicked(index);
}

void AppUIControl::uiEventWidgetUpdated(QString widgetId, QString event, QVariant data)
{
    emit widgetUpdated(widgetId, event, data);
}

bool AppUIControl::getHomeScreenAppVisibleProperty() const
{
    return m_appVisible;
}

void AppUIControl::handleHomeScreenAppVisibleChanged(bool val)
{
    if(m_appVisible != val) {
        m_appVisible = val;
        emit homeScreenAppVisibleChanged();
    }
}

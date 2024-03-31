#include "application.h"
#include "appmanageruicontrol.h"
#include "QDebug"

Application::Application(QString appId, QString appName, bool visible,int seq, QString appIcon):
    m_appId(appId), m_appName(appName), m_visible(visible), m_seq(seq), m_appIcon(appIcon)
{
    qDebug() << "Application create:";
    qDebug() << "appId:" << appId;
    qDebug() << "appName:" << appName;
    qDebug() << "visible:" << visible;
    qDebug() << "seq:" << seq;
    qDebug() << "appIcon:" << appIcon;

    eventHandlers["clicked"] = std::bind(&Application::clicked, this, std::placeholders::_1);
}

QString Application::id()  const
{
    return m_appId;
}

QString Application::appName()  const
{
    return m_appName;
}

QString Application::appIcon()  const
{
    return m_appIcon;
}

bool Application::visible()  const
{
    return m_visible;
}

int Application::seq()  const
{
    return m_seq;
}

void Application::clicked(QVariant data)
{
    Q_UNUSED(data);
    AppManagerUIControl::getInstance().requestShow(m_appId);
}

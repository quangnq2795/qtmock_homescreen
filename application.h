#ifndef UIAPPLICATION_H
#define UIAPPLICATION_H

#include <QObject>
#include <QString>

class Application
{
public:
    Application(QString appId, QString appName, bool visible,int seq, QString appIcon);

    QString appId() const;
    QString appName()  const;
    bool    visible()  const;
    int     seq()  const;
    QString appIcon()  const;

private:
    QString m_appId;
    QString m_appName;
    QString m_appIcon;
    bool    m_visible;
    int     m_seq;

};

#endif // UIAPPLICATION_H

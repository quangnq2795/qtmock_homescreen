#ifndef UIAPPLICATION_H
#define UIAPPLICATION_H

#include <QObject>
#include <QString>

#include "eventdata.h"
#include "icomponent.h"

class Application: public IComponent
{
public:
    Application(QString appId, QString appName, bool visible,int seq, QString appIcon);

    QString id() const override;
    QString appName()  const;
    bool    visible()  const;
    int     seq()  const;
    QString appIcon()  const;


private:
    void clicked(QVariant data);

private:
    QString m_appId;
    QString m_appName;
    QString m_appIcon;
    bool    m_visible;
    int     m_seq;

};

#endif // UIAPPLICATION_H

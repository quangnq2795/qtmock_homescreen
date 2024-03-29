#ifndef IWIDGET_H
#define IWIDGET_H

#include <QString>
#include <QVariant>

class IWidget {
public:
    virtual QString id() = 0;
    virtual void    handleEvent(QString event, QVariant data) = 0;
};

#endif // IWIDGET_H

#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include "icomponent.h"
#include <QMap>
#include <functional>

class MediaWidget: public IComponent
{
public:
    MediaWidget();

    QString id() const override;

private:

    void play(QVariant data);
    void pause(QVariant data);
    void next(QVariant data);
    void previous(QVariant data);
};

#endif // MEDIAWIDGET_H

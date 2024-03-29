#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include "iwidget.h"

class MediaWidget: public IWidget
{
public:
    MediaWidget();

    QString id() override;
    void    handleEvent(QString event, QVariant  data) override;
};

#endif // MEDIAWIDGET_H

#ifndef IAPPUICONTROLRECEIVER_H
#define IAPPUICONTROLRECEIVER_H

#include <QObject>
#include "iappuicontrol.h"
#include "iappuicontroladaptor.h"

class IAppUIControlReceiver: public IAppUIControl
{
    Q_OBJECT
public:
    IAppUIControlReceiver(QObject *parent = nullptr);

    bool setAppVisible(bool val) override;

signals:
    void appVisibleChanged(bool val);

private:
    IAppUIControlAdaptor* m_adapter;
};

#endif // IAPPUICONTROLRECEIVER_H

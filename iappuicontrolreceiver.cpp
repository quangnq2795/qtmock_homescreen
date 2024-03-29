#include "iappuicontrolreceiver.h"

IAppUIControlReceiver::IAppUIControlReceiver(QObject *parent):IAppUIControl(parent)
{
    m_adapter = new IAppUIControlAdaptor(this);

    auto connection =  new QDBusConnection(QDBusConnection::sessionBus());
    if (!connection->registerService("com.services.homescreen")) {
        qFatal("Could not register service!");
    }

    if (!connection->registerObject("/com/services/homescreen/uicontrol", this)) {
        qFatal("Could not register object!");
    }

    qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<"Register Done";
}

bool IAppUIControlReceiver::setAppVisible(bool val) {
    emit appVisibleChanged(val);
    return true;
}

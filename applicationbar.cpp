#include "applicationbar.h"
#include "application.h"
#include "appmanageruicontrol.h"

#include <QString>
#include <QDebug>

ApplicationBar::ApplicationBar(ApplicationModel* model, QObject *parent): m_appmodel(model)
{

}

void ApplicationBar::handleRunApplication(int appIndex)
{
    Application app = m_appmodel->getApplication(appIndex);
    QString     appId = app.appId();
    if(appId == "00000") {
        return;
    }

    qDebug() << "handleRunApplication " << appId;
    AppManagerUIControl::getInstance().requestShow(appId);
}

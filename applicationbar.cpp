#include "applicationbar.h"
#include "application.h"
#include "appmanageruicontrol.h"
#include "appmanagerappmodel.h"
#include "applicationmodel.h"

#include <QString>
#include <QDebug>

#include <functional>

ApplicationBar::ApplicationBar() : IUIBar()
{

    QList<Application*> appList = AppManagerAppModel::getInstance().getApplicationModelData();

    for (int i = appList.size() - 1; i >= 0; --i) {
        if(appList[i]->id() != "homescreen") {
            ApplicationModel::getInstance().addApplication(appList[i]);
        }

        addComponent(appList[i]);
    }
}

#ifndef APPMANAGERAPPMODEL_H
#define APPMANAGERAPPMODEL_H

#include "IAppManagerAppModel.h"
#include "application.h"
#include <QList>

class AppManagerAppModel
{
public:
    static AppManagerAppModel& getInstance()
    {
        static AppManagerAppModel instance;
        return instance;
    }


    QList<Application*> getApplicationModelData();

private:
    AppManagerAppModel(const AppManagerAppModel&) = delete;
    void operator=(const AppManagerAppModel&) = delete;

    AppManagerAppModel();

private:
    QSharedPointer<local::IAppManagerAppModel> m_appModel;
};

#endif // APPMANAGERAPPMODEL_H

#include "appmanagerappmodel.h"

AppManagerAppModel::AppManagerAppModel()
{
    m_appModel = QSharedPointer<local::IAppManagerAppModel>::create("com.services.appmanager", "/com/services/appmanager/appmodel", QDBusConnection::sessionBus());
}

QList<Application*> AppManagerAppModel::getApplicationModelData()
{
    QList<Application*> applicationList;
    QString jsonString= m_appModel->getApplicationModelData();


    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
        if (!jsonDoc.isArray()) {
            // Invalid JSON format, return empty list
            return applicationList;
        }

        // Convert JSON array to list of Application objects
        QJsonArray jsonArray = jsonDoc.array();
        for (const QJsonValue& jsonValue : jsonArray) {
            if (!jsonValue.isObject()) {
                // Skip invalid JSON object
                continue;
            }

            // Extract data from JSON object
            QJsonObject jsonObj = jsonValue.toObject();
            QString appId = jsonObj["appId"].toString();
            QString appName = jsonObj["appName"].toString();
            bool visible = jsonObj["visible"].toBool();
            int seq = jsonObj["seq"].toInt();
            QString appIcon = jsonObj["appIcon"].toString();

            // Create Application object and add to list
            Application* app = new Application(appId, appName, visible, seq, appIcon);
            applicationList.append(app);
        }

        return applicationList;
}

// applicationmodel.cpp
#include "applicationmodel.h"
#include "appmanagerappmodel.h"
#include "QDebug"


ApplicationModel::ApplicationModel(QObject *parent)
    : QAbstractListModel(parent)
{
    qDebug() << "ApplicationModel create";

    m_data = AppManagerAppModel::getInstance().getApplicationModelData();

    for (int i = m_data.size() - 1; i >= 0; --i) {
        if (m_data[i].appId() == "homescreen") {
            m_data.removeAt(i);
            break;
        }
    }
}

int ApplicationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_data.size();
}

QVariant ApplicationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_data.size())
        return QVariant();

    const Application &item = m_data.at(index.row());

    switch (role) {
    case Qt::UserRole + 1: // AppTypeRole
        return item.appId();
    case Qt::UserRole + 2: // IconSourceRole
        return item.appIcon();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ApplicationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "appType";
    roles[Qt::UserRole + 2] = "iconSource";
    return roles;
}

void ApplicationModel::addApplication(Application app) {
    bool isAppExits = false;
    QString appId = app.appId();

    for (const Application &m_app : m_data) {
        if(appId == m_app.appId()) {
            isAppExits = true;
            break;
        }
    }

    if(!isAppExits) {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_data.append(app);
        endInsertRows();
    }
}

Application ApplicationModel::getApplication(int appIndex){
    if(appIndex < 0 || appIndex >= m_data.size()) {
        return Application("00000","invalid",false,-1,"invalid");
    }

    return m_data[appIndex];
}

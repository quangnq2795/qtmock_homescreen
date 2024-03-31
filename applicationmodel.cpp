#include "applicationmodel.h"
#include "appmanagerappmodel.h"
#include "QDebug"

ApplicationModel::ApplicationModel()
    : QAbstractListModel(nullptr)
{
    qDebug() << "ApplicationModel create";
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

    const Application* item = m_data.at(index.row());

    switch (role) {
    case Qt::UserRole + 1: // AppTypeRole
        return item->id();
    case Qt::UserRole + 2: // IconSourceRole
        return item->appIcon();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ApplicationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "appid";
    roles[Qt::UserRole + 2] = "iconSource";
    return roles;
}

void ApplicationModel::addApplication(Application* app) {
    bool isAppExits = false;
    QString appId = app->id();

    for (const Application* m_app : m_data) {
        if(appId == m_app->id()) {
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


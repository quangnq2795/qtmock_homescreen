#ifndef APPLICATIONMODEL_H
#define APPLICATIONMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QVariant>

#include "application.h"

class ApplicationModel : public QAbstractListModel
{
    Q_OBJECT

public:
    static ApplicationModel& getInstance() {
        static ApplicationModel instance;
        return instance;
    }

    // Delete copy constructor and assignment operator
    ApplicationModel(ApplicationModel const&) = delete;
    void operator=(ApplicationModel const&) = delete;

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addApplication(Application* app);

private:
    ApplicationModel();
    ~ApplicationModel() = default;

    QList<Application*> m_data;
};

#endif

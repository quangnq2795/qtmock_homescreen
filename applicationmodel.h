// applicationmodel.h
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
    explicit ApplicationModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addApplication(Application app);
    Application getApplication(int appIndex);
private:

    QList<Application> m_data;
};

#endif // APPLICATIONMODEL_H

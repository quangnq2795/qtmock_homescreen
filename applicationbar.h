#ifndef APPLICATIONBAR_H
#define APPLICATIONBAR_H

#include <QObject>

#include "applicationmodel.h"


class ApplicationBar: public QObject
{
    Q_OBJECT
public:
    ApplicationBar(ApplicationModel* model, QObject *parent = nullptr);

public slots:
    void handleRunApplication(int appIndex);

private:
    ApplicationModel* m_appmodel;
};

#endif // APPLICATIONBAR_H

#ifndef APPLICATIONBAR_H
#define APPLICATIONBAR_H

#include <QObject>
#include <QMap>

#include "iuibar.h"
#include "applicationmodel.h"


class ApplicationBar: public IUIBar
{
    Q_OBJECT
public:
    ApplicationBar();
};

#endif // APPLICATIONBAR_H

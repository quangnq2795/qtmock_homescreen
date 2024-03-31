#ifndef IComponent_H
#define IComponent_H

#include <QString>
#include <QVariant>

class IComponent {
public:
    virtual QString id() const = 0;

    void    handleEvent(QString event, QVariant data);

protected:
     QMap<QString, std::function<void(QVariant)>> eventHandlers;
};

#endif // IComponent_H

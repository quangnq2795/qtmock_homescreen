#ifndef APPUICONTROL_H
#define APPUICONTROL_H

#include <QObject>
#include <QMap>

#include "iuibar.h"
#include "applicationbar.h"
#include "widgetbar.h"
#include "iappuicontrolreceiver.h"

class AppUIControl: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isVisible READ getVisibleProperty NOTIFY visibleChanged)

    Q_PROPERTY(bool    songPlaying READ getSongPlaying NOTIFY songPlayingChanged)
    Q_PROPERTY(QString songSinger READ getSongSinger NOTIFY songSingerChanged)
    Q_PROPERTY(QString songTitle READ getSongTitle NOTIFY songTitleChanged)
    Q_PROPERTY(QString songImage READ getSongImage NOTIFY songImageChanged)
    Q_PROPERTY(QString songDuration READ getSongDuration NOTIFY songDurationChanged)
    Q_PROPERTY(float   songPlayingTime READ getSongPlayingTime NOTIFY songTimeChanged)

public:
    AppUIControl(ApplicationBar* appBar, WidgetBar *widgetBar, QObject* parent = nullptr);

    Q_INVOKABLE void uiEvent(QVariant eData);

public slots:
    void handleAppVisibleChanged(bool val);

signals:
    void visibleChanged();
    void songPlayingChanged();
    void songSingerChanged();
    void songTitleChanged();
    void songImageChanged();
    void songDurationChanged();
    void songTimeChanged();

private:
    bool    getVisibleProperty() const;
    bool    getSongPlaying() const;
    QString getSongSinger() const;
    QString getSongTitle() const;
    QString getSongImage() const;
    QString getSongDuration() const;
    float   getSongPlayingTime() const;

private:
    bool m_appVisible;

    QMap<QString,IUIBar*> m_uiBarList;
    IAppUIControlReceiver* m_UIControlReceiver;
};

#endif // APPUICONTROL_H

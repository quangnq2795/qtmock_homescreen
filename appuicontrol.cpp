#include "appuicontrol.h"
#include "appmanageruicontrol.h"
#include "mediaplayercontrol.h"
AppUIControl::AppUIControl(ApplicationBar* appBar, WidgetBar *widgetBar, QObject* parent)
{
    qDebug() << "HomeScreen startup";

    m_uiBarList["appbar"] = appBar;
    m_uiBarList["widgetbar"] = widgetBar;

    m_UIControlReceiver = new IAppUIControlReceiver();
    connect(m_UIControlReceiver, &IAppUIControlReceiver::appVisibleChanged, this, &AppUIControl::handleAppVisibleChanged);

    connect(MediaPlayer::getInstance(), &MediaPlayer::songPlayingChanged, this, &AppUIControl::songPlayingChanged);
    connect(MediaPlayer::getInstance(), &MediaPlayer::songSingerChanged, this, &AppUIControl::songSingerChanged);
    connect(MediaPlayer::getInstance(), &MediaPlayer::songTitleChanged, this, &AppUIControl::songTitleChanged);
    connect(MediaPlayer::getInstance(), &MediaPlayer::songImageChanged, this, &AppUIControl::songImageChanged);
    connect(MediaPlayer::getInstance(), &MediaPlayer::songDurationChanged, this, &AppUIControl::songDurationChanged);
    connect(MediaPlayer::getInstance(), &MediaPlayer::songTimeChanged, this, &AppUIControl::songTimeChanged);

    m_appVisible = AppManagerUIControl::getInstance().getAppVisible("homescreen");
}

void AppUIControl::handleAppVisibleChanged(bool val)
{
    if(m_appVisible != val) {
        m_appVisible = val;
        emit visibleChanged();
    }
}

void AppUIControl::uiEvent(QVariant eData)
{
    if (eData.canConvert<QVariantMap>()) {
        QVariantMap eventDataMap = eData.toMap();
        QString bid = eventDataMap.value("bid").toString();
        QString cid = eventDataMap.value("cid").toString();
        QString event = eventDataMap.value("event").toString();
        QVariant data = eventDataMap.value("data");

        // Create an EventData object
        EventData eventData(bid,cid,event,data);

        if (m_uiBarList.contains(bid)) {
            IUIBar* handler = m_uiBarList.value(bid);
            handler->emitEvent(eventData);
        } else {
            qDebug() << "No handler widget for ID:" << bid;
        }
    } else {
        qDebug() << "Invalid QVariant type for event data";
    }
}


bool AppUIControl::getVisibleProperty() const
{
    return m_appVisible;
}

bool AppUIControl::getSongPlaying() const
{
    return MediaPlayer::getInstance()->getPlayerState();
}

QString AppUIControl::getSongSinger() const
{
    return MediaPlayer::getInstance()->getSongSinger();
}

QString AppUIControl::getSongTitle() const
{
    return MediaPlayer::getInstance()->getSongTitle();
}

QString AppUIControl::getSongImage() const
{
    return MediaPlayer::getInstance()->getSongImage();
}

int AppUIControl::getSongDuration() const
{
    return MediaPlayer::getInstance()->getSongDuration();
}

int AppUIControl::getSongPlayingTime() const
{
    return MediaPlayer::getInstance()->getSongPlayingTime();
}

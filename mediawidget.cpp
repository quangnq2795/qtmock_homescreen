#include "mediawidget.h"
#include "mediaplayercontrol.h"


MediaWidget::MediaWidget()
{
    eventHandlers["play"] = std::bind(&MediaWidget::play, this, std::placeholders::_1);
    eventHandlers["pause"] = std::bind(&MediaWidget::pause, this, std::placeholders::_1);
    eventHandlers["next"] = std::bind(&MediaWidget::next, this, std::placeholders::_1);
    eventHandlers["previous"] = std::bind(&MediaWidget::previous, this, std::placeholders::_1);
}

QString MediaWidget::id() const
{
    return "mediawidget";
}

void MediaWidget::play(QVariant data)
{
    Q_UNUSED(data);
    MediaPlayer::getInstance()->play();
}

void MediaWidget::pause(QVariant data)
{
    Q_UNUSED(data);
    MediaPlayer::getInstance()->pause();
}

void MediaWidget::next(QVariant data)
{
    Q_UNUSED(data);
    MediaPlayer::getInstance()->next();
}

void MediaWidget::previous(QVariant data)
{
    Q_UNUSED(data);
    MediaPlayer::getInstance()->previous();
}

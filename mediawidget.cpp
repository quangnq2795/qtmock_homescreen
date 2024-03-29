#include "mediawidget.h"
#include "mediaplayercontrol.h"

MediaWidget::MediaWidget()
{

}

QString MediaWidget::id()
{
    return "mediawidget";
}

void MediaWidget::handleEvent(QString event, QVariant data)
{
    (void)data;

    if(event == "play") {
        MediaPlayer::getInstance()->play();
    } else if (event == "pause") {
        MediaPlayer::getInstance()->pause();
    } else if (event == "next") {
        MediaPlayer::getInstance()->next();
    } else if ( event == "previous") {
        MediaPlayer::getInstance()->previous();
    } else {

    }
}

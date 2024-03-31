#include "mediaplayercontrol.h"

MediaPlayer *MediaPlayer::instance = nullptr;

MediaPlayer::MediaPlayer()
{
    m_mediaPlayer = new local::IMediaPlayerControl("com.services.mediaplayer", "/com/services/mediaplayer/mediacontrol", QDBusConnection::sessionBus());
    
    connect(m_mediaPlayer, SIGNAL(playerStateChanged(bool)), this, SLOT(handleMediaPlayerStateChanged(bool)));
    connect(m_mediaPlayer, SIGNAL(playerTimePlayingChanged(int)), this, SLOT(handleSongPlayingTimeChanged(int)));
    connect(m_mediaPlayer, SIGNAL(playerSongPlayingChanged(int, QString,QString, QString,int)), this, SLOT(handleSongPlayingChanged(int, QString,QString, QString,int)));

    getDefaulSongPlayingInfo();
}

bool MediaPlayer::play()
{
    return m_mediaPlayer->play();
}

bool MediaPlayer::pause()
{
    return m_mediaPlayer->pause();
}

bool MediaPlayer::next()
{
    return m_mediaPlayer->next();
}

bool MediaPlayer::previous()
{
    return m_mediaPlayer->previous();
}

bool MediaPlayer::getPlayerState()
{
    return m_isPlaying;
}

QString MediaPlayer::getSongTitle()
{
    return m_songTitle;
}

QString MediaPlayer::getSongSinger()
{
    return m_songSinger;
}

QString MediaPlayer::getSongImage()
{
    return m_songImage;
}
int MediaPlayer::getSongDuration()
{
    return m_songDuration;
}

int MediaPlayer::getSongPlayingTime()
{
    return m_playingTime;
}

void MediaPlayer::handleSongPlayingChanged(int songId, const QString& songName,const QString& singer, const QString& imagePath, int totalTime)
{
    if(songName != m_songTitle) {
        m_songTitle = songName;
        emit songTitleChanged();
    }

    if(singer != m_songSinger) {
        m_songSinger = singer;
        emit songSingerChanged();
    }

    if(imagePath != m_songImage) {
        m_songImage = imagePath;
        emit songImageChanged();
    }

    if(totalTime != m_songDuration) {
        m_songDuration = totalTime;
        emit songDurationChanged();
    }
}

void MediaPlayer::handleMediaPlayerStateChanged(bool isPlaying)
{
    if(isPlaying != m_isPlaying) {
        m_isPlaying = isPlaying;
        emit songPlayingChanged();
    }
}

void MediaPlayer::handleSongPlayingTimeChanged(int time)
{
    if(m_playingTime != time) {
        m_playingTime = time;
        emit songTimeChanged();
    }
}

void MediaPlayer::getDefaulSongPlayingInfo()
{
    int songId = -1;
    QString songName;
    QString singer;
    QString imagePath; 
    int totalTime;
    int playingTime;

    bool result = m_mediaPlayer->getSongPlaying(songId, songName, singer, imagePath, totalTime);
    if(result) {

        if(songName != m_songTitle) {
            m_songTitle = songName;
            emit songTitleChanged();
        }

        if(singer != m_songSinger) {
            m_songSinger = singer;
            emit songSingerChanged();
        }

        if(imagePath != m_songImage) {
            m_songImage = imagePath;
            emit songImageChanged();
        }

        if(totalTime != m_songDuration) {
            m_songDuration = totalTime;
            emit songDurationChanged();
        }

    } else {
        qDebug() << "getSongPlaying " << result;
    }

    result= m_mediaPlayer->getTimePlaying(playingTime);
    if(result) {
        if(m_playingTime != playingTime)
        {
            m_playingTime = playingTime;
            emit songTimeChanged();
        }
    }

    bool isPlaying = m_mediaPlayer->isPlaying();
    if(isPlaying != m_isPlaying) {
        m_isPlaying = isPlaying;
        emit songPlayingChanged();
    }
}

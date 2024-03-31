#ifndef MEDIAPLAYERCONTROL_H
#define MEDIAPLAYERCONTROL_H

#include <QObject>
#include "IMediaPlayerControl.h"

class MediaPlayer: public QObject
{
    Q_OBJECT
public:
    static MediaPlayer *getInstance()
    {
        if(instance == nullptr)
        {
            instance = new MediaPlayer;
        }
        return instance;
    }

    bool play();
    bool pause();
    bool next();
    bool previous();

    bool    getPlayerState();
    QString getSongTitle();
    QString getSongSinger();
    QString getSongImage();
    int     getSongDuration();
    int     getSongPlayingTime();

public slots:
    void handleSongPlayingChanged(int songId, const QString& songName, const QString& singer, const QString& imagePath, int totalTime);
    void handleMediaPlayerStateChanged(bool isPlaying);
    void handleSongPlayingTimeChanged(int time);

signals:
    void songPlayingChanged();
    void songSingerChanged();
    void songTitleChanged();
    void songImageChanged();
    void songDurationChanged();
    void songTimeChanged();

private:
    MediaPlayer(const MediaPlayer&) = delete;
    void operator=(const MediaPlayer&) = delete;

    MediaPlayer();

    void    getDefaulSongPlayingInfo();

private:
    local::IMediaPlayerControl* m_mediaPlayer;

    bool    m_isPlaying;
    QString m_songTitle;
    QString m_songSinger;
    QString m_songImage;
    int     m_playingTime;
    int     m_songDuration;


    static MediaPlayer *instance;
};

#endif // MEDIAPLAYERCONTROL_H

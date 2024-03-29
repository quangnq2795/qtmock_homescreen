#ifndef MEDIAPLAYERCONTROL_H
#define MEDIAPLAYERCONTROL_H

#include <QObject>
#include "IMediaPlayerControl.h"

class MediaPlayer: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MediaPlayer)
    Q_PROPERTY(bool    isPlaying READ getPlayerState NOTIFY mediaPlayerStateChanged)
    Q_PROPERTY(QString songTitle READ getSongTitle NOTIFY mediaPlayingSongTitleChanged)
    Q_PROPERTY(QString songSinger READ getSongSinger NOTIFY mediaPlayingSongSingerChanged)
    Q_PROPERTY(QString songImage READ getSongImage NOTIFY mediaPlayingSongImageChanged)
    Q_PROPERTY(int     songPlayingTime READ getSongPlayingTime NOTIFY mediaSongPlayingTimeChanged)
    Q_PROPERTY(int     songTotalTime READ getSongDuration NOTIFY mediaPlayingSongDurationChanged)

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

public slots:
    void handleSongPlayingChanged(int songId, const QString& songName, const QString& singer, const QString& imagePath, int totalTime);
    void handleMediaPlayerStateChanged(bool isPlaying);
    void handleSongPlayingTimeChanged(int time);

signals:
    void songPlayingChanged(int songId, const QString& songName, const QString& singer, const QString& imagePath, int totalTime);
    void mediaPlayingSongTitleChanged();
    void mediaPlayingSongSingerChanged();
    void mediaPlayingSongImageChanged();
    void mediaPlayingSongDurationChanged();
    void mediaPlayerStateChanged();
    void mediaSongPlayingTimeChanged();

private:
    //MediaPlayer(const MediaPlayer&) = delete;
    //void operator=(const MediaPlayer&) = delete;

    MediaPlayer();

    bool    getPlayerState();
    QString getSongTitle();
    QString getSongSinger();
    QString getSongImage();
    int     getSongDuration();
    int     getSongPlayingTime();

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

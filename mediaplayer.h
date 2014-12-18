#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "vlc/vlc.h"
//#include "vlc-qt/WidgetVideo.h"
#include "equalizer.h"

#include <QX11EmbedContainer>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include <QFrame>


class mediaPlayer
{
public:
    mediaPlayer();
    ~mediaPlayer();
    void playSong(QString );
    void stopSong(void);
    void pauseSong(void);
    int isPlaying(void);
    void PlayVideo(char *, u_int32_t );
    int64_t GetLength (void);
    int GetTime (void);
    equalizer equ;
    QX11EmbedContainer mediaWidget;
    void updateEqualiser(void);




private:
    libvlc_instance_t *inst;


    libvlc_media_player_t *thisPlayer;
    libvlc_media_t *mediaPath;




};

#endif // MEDIAPLAYER_H

#include "mediaplayer.h"
#include "vlc/vlc.h"
//#include "vlc-qt/Audio.h"
//#include "vlc-qt/WidgetVideo.h"
#include <QDebug>

 #include <QX11EmbedContainer>



mediaPlayer::mediaPlayer()
{
    inst = libvlc_new(0, NULL);
    thisPlayer = libvlc_media_player_new(inst);
    equ.setEqualizer(thisPlayer);
}

mediaPlayer::~mediaPlayer()
{
    libvlc_media_player_release(thisPlayer);
    libvlc_release(inst);
}


void mediaPlayer::updateEqualiser(void){
    equ.setEqualizer(thisPlayer);
}

void mediaPlayer::playSong(QString filePath){

    // create a new item
    mediaPath = libvlc_media_new_path(inst, filePath.toLocal8Bit());
    // create a media play playing environment
    libvlc_media_player_set_media(thisPlayer, mediaPath);
    // no need to keep the media now
    libvlc_media_release(mediaPath);
    libvlc_media_player_play(thisPlayer);
    //equ.setEqualizer(thisPlayer);
}

int mediaPlayer::isPlaying(void){

   return libvlc_media_player_is_playing(thisPlayer);
}

void mediaPlayer::stopSong(void){

    // stop playing
    libvlc_media_player_stop(thisPlayer);
}

void mediaPlayer::pauseSong(void){

    libvlc_media_player_pause(thisPlayer);
}

int64_t mediaPlayer::GetLength(void)
{
    int64_t length = libvlc_media_player_get_length(thisPlayer);
    qDebug () << ((length/1000) /60) << "." << ((length/1000) %60);
    return length;
}

int mediaPlayer::GetTime(void)
{

     return libvlc_media_player_get_time(thisPlayer);
}

void mediaPlayer::PlayVideo(char *a, u_int32_t i)
{
    // create a new item
    mediaPath = libvlc_media_new_path(inst, a);

    // create a media play playing environment
    //thisPlayer = libvlc_media_player_new_from_media(mediaPath);

    // no need to keep the media now
    libvlc_media_release(mediaPath);

    libvlc_media_player_set_xwindow (thisPlayer, i );

    libvlc_media_player_play(thisPlayer);
    //mediaWidget.show();
}


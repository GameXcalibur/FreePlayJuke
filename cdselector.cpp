#include "cdselector.h"
#include <QDebug>
#include "mainwindow.h"
#include <string>


CDSelector::CDSelector(QObject *parent) : QObject(parent)
{

    mediaReader = new fileIO;
    CDTitles = mediaReader->GetCDList(QString("Media"));
    CDCoverInfo.curPageIndex = 0;
    CDCoverInfo.curMediaIndex = 0;
    player = new mediaPlayer;

    numberOfAlbums = CDTitles.count();




}

//CDSelector::~CDSelector(){


    //delete player;
   // delete mediaReader;
//}

void CDSelector::LoadCDCovers(void)
{
    CDCoverInfo.curPageIndex = CDCoverInfo.curMediaIndex;
    while( CDCoverInfo.curPageIndex < (CDCoverInfo.curMediaIndex + NUM_SELECT_ICONS) ){

        if(CDCoverInfo.curPageIndex < numberOfAlbums)
        {
            if(QFile::exists(QString("Media/" + CDTitles.at(CDCoverInfo.curPageIndex) + "/coverart.png")))
                CDCoverInfo.coverArt =  QIcon(QString("Media/" + CDTitles.at(CDCoverInfo.curPageIndex) + "/coverart.png"));
            else
                CDCoverInfo.coverArt = QIcon (QString("res/defaultCDCover.png"));
            temp = CDTitles.at(CDCoverInfo.curPageIndex).split("-");
            CDCoverInfo.artist = temp.at(0);
            CDCoverInfo.album = temp.at(1);
            CDCoverInfo.iconSize = QSize(250, 250);

        }else{

            CDCoverInfo.artist = QString(" ");
            CDCoverInfo.coverArt = QIcon (QString("res/defaultCDCover.png"));
        }
        emit drawCDCovers(CDCoverInfo);
        CDCoverInfo.curPageIndex++;



    }

}

void CDSelector::Prev(void){

    CDCoverInfo.curMediaIndex -= NUM_SELECT_ICONS;
    if(CDCoverInfo.curMediaIndex < 0)
        CDCoverInfo.curMediaIndex = numberOfAlbums - (numberOfAlbums %NUM_SELECT_ICONS);
    LoadCDCovers();
}


void CDSelector::Next(void){

   CDCoverInfo.curMediaIndex += NUM_SELECT_ICONS;
   if(CDCoverInfo.curMediaIndex >= numberOfAlbums)
       CDCoverInfo.curMediaIndex = 0;
    LoadCDCovers();
}

CDINFO CDSelector::GetSelectedAlbum(int pushedButton){

    CDInfo.iconSize = QSize(560, 560);
    CDInfo.artist = CDTitles.at(CDCoverInfo.curMediaIndex + pushedButton);
    CDInfo.coverArt = QPixmap(QString("Media/" + CDTitles.at(CDCoverInfo.curMediaIndex + pushedButton) + "/coverart.png"));
    CDInfo.coverArt = CDInfo.coverArt.scaled(CDInfo.iconSize);
    CDInfo.filePath = QString("Media/" + CDTitles.at(CDCoverInfo.curMediaIndex + pushedButton));
    CDInfo.songList = mediaReader->GetSongList(CDInfo.filePath);
    CDInfo.numberOfSongs = CDInfo.songList.count();
    CDInfo.indexPtr = 0;

    return CDInfo;


}


void CDSelector::PlaySelectedSong(qint32 index){

    player->playSong(QString(CDInfo.filePath + "/" + CDInfo.songList.at(index) + ".mp3"));



}

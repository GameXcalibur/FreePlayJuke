#include "fileio.h"
#include <QApplication>
#include <QDir>
#include <QDebug>

fileIO::fileIO()
{



}

QStringList fileIO::GetCDList(QString path){


    QDir mediaDir(path);
    mediaDir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    QStringList mediaItems = mediaDir.entryList();
    return mediaItems;

}


QStringList fileIO::GetSongList(QString path){


    QDir mediaDir(path);
    mediaDir.setFilter(QDir::NoDotAndDotDot | QDir::Files);
    QStringList filter;
    filter << "*.mp3";
    mediaDir.setNameFilters(filter);
    QStringList mediaItems = mediaDir.entryList();
    mediaItems.replaceInStrings(".mp3", "");
    return mediaItems;


}


void fileIO::CreateFolders(void){

    for (int i = 0; i < 8; i++){
        QString temp = "media/Test" + i;
        mediaDir.mkdir(temp);
    }


}


#ifndef CDSELECTOR_H
#define CDSELECTOR_H
#include <QObject>
#include <QStringList>
#include "fileio.h"
#include <QIcon>
#include <QStringListModel>
#include <QPixmap>
#include "mediaplayer.h"
#include <QQueue>

#define NUM_SELECT_ICONS 6
#define NUM_SELECT_SONGS 12

typedef struct {

    qint32 curMediaIndex;
    qint32 curPageIndex;
    QSize iconSize;
    QIcon coverArt;
    QString artist;
    QString album;

}CDCOVERINFO;

typedef struct {

    QString artist;
    QString album;
    QPixmap coverArt;
    QStringList songList;
    QSize iconSize;
    QString filePath;
    qint32 numberOfSongs;
    qint32 indexPtr;
    qint32 index;

}CDINFO;


class CDSelector : public QObject
{
    Q_OBJECT
public:
    explicit CDSelector(QObject* parent = 0);
    void LoadCDCovers(void);
    void Prev(void);
    void Next(void);
    void PlaySelectedSong(qint32 );
    CDINFO GetSelectedAlbum(int pushedButton);
private:
    //~CDSelector();
    QStringList CDTitles;
    fileIO *mediaReader;
    mediaPlayer *player;
    CDCOVERINFO CDCoverInfo;
    CDINFO CDInfo;
    int numberOfAlbums;
    QStringList temp;



signals:
    void drawCDCovers(CDCOVERINFO);
};

#endif // CDSELECTOR_H

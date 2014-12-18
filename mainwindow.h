#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define MEDIA_PLAYER       0
#define MEDIA_LIST         1
#define MEDIA_CDSELECT     2
#define MEDIA_SONGSELECT   3
#define MEDIA_EQUALIZER    4



#include <QMainWindow>
#include "mediaplayer.h"
//#include "vlc-qt/WidgetVideo.h"
#include "fileio.h"
#include "cdselector.h"
#include "equalizer.h"
#include <QIcon>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QX11EmbedContainer* mediaWidget;
    //QStringList CDList = fileReader->GetList(QString("media"));


    
private slots:
    void on_bPlay_clicked();
    void on_bStop_clicked();
    void on_bPause_clicked();

    void on_bCurrentTime_clicked();
    void on_bDuration_clicked();
    void on_bQuit_clicked();
    void on_bNextPage_clicked();
    void on_bBack_clicked();
    void on_bGetList_clicked();
    void on_bCreateList_clicked();
    void on_bPrev_clicked();
    void on_bNext_clicked();

    void on_bSonga_clicked();
    void on_bSongb_clicked();
    void on_bSongc_clicked();
    void on_bSongd_clicked();
    void on_bSonge_clicked();
    void on_bSongf_clicked();
    void on_bSongg_clicked();
    void on_bSongh_clicked();
    void on_bSongi_clicked();
    void on_bSongj_clicked();
    void on_bSongk_clicked();
    void on_bSongl_clicked();

    void on_bSongDn_clicked();
    void on_bSongUp_clicked();

    void on_bCDa_clicked();
    void on_bCDb_clicked();
    void on_bCDc_clicked();
    void on_bCDd_clicked();
    void on_bCDe_clicked();
    void on_bCDf_clicked();

    void on_bSongSelBack_clicked();
     void MainEngineLoop(void);



     void on_vsPreamp_valueChanged(int value);

     void on_vsBand1_valueChanged(int value);

     void on_vsBand2_valueChanged(int value);

     void on_vsBand3_valueChanged(int value);

     void on_vsBand4_valueChanged(int value);

     void on_vsBand5_valueChanged(int value);

     void on_vsBand6_valueChanged(int value);

     void on_vsBand7_valueChanged(int value);

     void on_vsBand8_valueChanged(int value);

     void on_vsBand9_valueChanged(int value);

     void on_vsBand10_valueChanged(int value);

     void on_cbEqPresets_currentIndexChanged(int index);

public slots:
        void setCDSelectorIcon(CDCOVERINFO);

private:
    Ui::MainWindow *ui;
    mediaPlayer* mp;
    fileIO* fileReader;
    CDSelector* cdSelector;
    mediaPlayer* mp1;
    //VlcWidgetVideo* videoWidget;
    QString number;
    QSize VideoFrameSize;
    CDINFO CDInfo;
    QStringList songQueue;
    qint32 numQueuedSongs;
    QTimer *mainEngineTimer;


    void PopulateSongList(CDINFO);
    void EquUpdateVals(void);



};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mediaplayer.h"
//#include "vlc-qt/WidgetVideo.h"
#include "fileio.h"
#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mp = new mediaPlayer();
    fileReader = new fileIO();
    cdSelector = new CDSelector();
    VideoFrameSize = ui->VideoFrame->geometry().size();
    mainEngineTimer = new QTimer();

    mediaWidget = new QX11EmbedContainer((QWidget *)ui->VideoFrame );
    mediaWidget->resize(VideoFrameSize);
    connect(cdSelector,SIGNAL(drawCDCovers(CDCOVERINFO)),this,SLOT(setCDSelectorIcon(CDCOVERINFO)));
    connect(mainEngineTimer,SIGNAL(timeout()),this,SLOT(MainEngineLoop()));

    cdSelector->LoadCDCovers();
    mainEngineTimer->start(20);


}

MainWindow::~MainWindow()
{
    disconnect(mainEngineTimer,SIGNAL(timeout()),this,SLOT(MainEngineLoop()));
    disconnect(cdSelector,SIGNAL(drawCDCovers(CDCOVERINFO)),this,SLOT(setCDSelectorIcon(CDCOVERINFO)));
    delete mainEngineTimer;
    delete cdSelector;
    delete fileReader;
    delete mp;
    delete ui;
}

void MainWindow::MainEngineLoop(void){

    if( (songQueue.count() > 0) && (mp->isPlaying() == 0)){
          mp->playSong(songQueue.takeFirst());

    }

}

void MainWindow::EquUpdateVals(void){

    ui->lPreampVal->setNum(mp->equ.getPreamp());
    ui->lBand1Val->setNum(mp->equ.getBand(0));
    ui->lBand2Val->setNum(mp->equ.getBand(1));
    ui->lBand3Val->setNum(mp->equ.getBand(2));
    ui->lBand4Val->setNum(mp->equ.getBand(3));
    ui->lBand5Val->setNum(mp->equ.getBand(4));
    ui->lBand6Val->setNum(mp->equ.getBand(5));
    ui->lBand7Val->setNum(mp->equ.getBand(6));
    ui->lBand8Val->setNum(mp->equ.getBand(7));
    ui->lBand9Val->setNum(mp->equ.getBand(8));
    ui->lBand10Val->setNum(mp->equ.getBand(9));
    ui->vsPreamp->setValue(mp->equ.getPreamp());
    ui->vsBand1->setValue(mp->equ.getBand(0));
    ui->vsBand2->setValue(mp->equ.getBand(1));
    ui->vsBand3->setValue(mp->equ.getBand(2));
    ui->vsBand4->setValue(mp->equ.getBand(3));
    ui->vsBand5->setValue(mp->equ.getBand(4));
    ui->vsBand6->setValue(mp->equ.getBand(5));
    ui->vsBand7->setValue(mp->equ.getBand(6));
    ui->vsBand8->setValue(mp->equ.getBand(7));
    ui->vsBand9->setValue(mp->equ.getBand(8));
    ui->vsBand10->setValue(mp->equ.getBand(9));
    mp->updateEqualiser();
}

void MainWindow::setCDSelectorIcon(CDCOVERINFO CDCoverInfo){

    switch(CDCoverInfo.curPageIndex %NUM_SELECT_ICONS){
        case 0:
            ui->bCDa->setIcon(CDCoverInfo.coverArt);
            ui->bCDa->setIconSize(CDCoverInfo.iconSize);
            ui->lCDa->setText(CDCoverInfo.artist);
            break;
        case 1:
            ui->bCDb->setIcon(CDCoverInfo.coverArt);
            ui->bCDb->setIconSize(CDCoverInfo.iconSize);
            ui->lCDb->setText(CDCoverInfo.artist);
            break;
        case 2:
            ui->bCDc->setIcon(CDCoverInfo.coverArt);
            ui->bCDc->setIconSize(CDCoverInfo.iconSize);
            ui->lCDc->setText(CDCoverInfo.artist);
            break;
        case 3:
            ui->bCDd->setIcon(CDCoverInfo.coverArt);
            ui->bCDd->setIconSize(CDCoverInfo.iconSize);
            ui->lCDd->setText(CDCoverInfo.artist);
            break;
        case 4:
            ui->bCDe->setIcon(CDCoverInfo.coverArt);
            ui->bCDe->setIconSize(CDCoverInfo.iconSize);
            ui->lCDe->setText(CDCoverInfo.artist);
            break;
        case 5:
            ui->bCDf->setIcon(CDCoverInfo.coverArt);
            ui->bCDf->setIconSize(CDCoverInfo.iconSize);
            ui->lCDf->setText(CDCoverInfo.artist);
            break;
        default:
            break;
    }

 }

void MainWindow::on_bPlay_clicked()
{

    mp->PlayVideo("lahey.mp4", mediaWidget->winId());

}

void MainWindow::on_bStop_clicked()
{
    mp->stopSong();
}

void MainWindow::on_bPause_clicked()
{
    mp->pauseSong();

}

void MainWindow::on_bCurrentTime_clicked()
{

    //ui->progressBar->setValue(mp->GetTime());
}

void MainWindow::on_bDuration_clicked()
{
    //ui->lcdNumber->intValue(mp->GetLength());

}

void MainWindow::on_bQuit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_bNextPage_clicked()
{
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_LIST);

}

void MainWindow::on_bBack_clicked()
{
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_PLAYER);
}

void MainWindow::on_bGetList_clicked()
{
   // ui->mediaList->addItems(CDList);



}

void MainWindow::on_bCreateList_clicked()
{
    //fileReader->CreateFolders();
    //ui->mediaList->


}

void MainWindow::on_bPrev_clicked()
{
    cdSelector->Prev();
}

void MainWindow::on_bNext_clicked()
{
    cdSelector->Next();
}



void MainWindow::on_bCDa_clicked()
{
    CDInfo = cdSelector->GetSelectedAlbum(0);
    //ui->lSelCD->setIconSize(CDInfo.iconSize);
    ui->lSelCD->setPixmap(CDInfo.coverArt);
    PopulateSongList(CDInfo);


}

void MainWindow::on_bCDb_clicked()
{
    CDInfo = cdSelector->GetSelectedAlbum(1);
   // ui->lSelCD->setIconSize(CDInfo.iconSize);
    ui->lSelCD->setPixmap(CDInfo.coverArt);
    PopulateSongList(CDInfo);
}

void MainWindow::on_bCDc_clicked()
{
    CDInfo = cdSelector->GetSelectedAlbum(2);
    //ui->lSelCD->setIconSize(CDInfo.iconSize);
    ui->lSelCD->setPixmap(CDInfo.coverArt);
    PopulateSongList(CDInfo);
}

void MainWindow::on_bCDd_clicked()
{
    CDInfo = cdSelector->GetSelectedAlbum(3);
    //ui->lSelCD->setp(CDInfo.iconSize);
    ui->lSelCD->setPixmap(CDInfo.coverArt);
    PopulateSongList(CDInfo);

}

void MainWindow::on_bCDe_clicked()
{
    CDInfo = cdSelector->GetSelectedAlbum(4);
    //ui->lSelCD->setp(CDInfo.iconSize);
    ui->lSelCD->setPixmap(CDInfo.coverArt);
    PopulateSongList(CDInfo);
}

void MainWindow::on_bCDf_clicked()
{
    CDInfo = cdSelector->GetSelectedAlbum(5);
    //ui->lSelCD->setp(CDInfo.iconSize);
    ui->lSelCD->setPixmap(CDInfo.coverArt);
    PopulateSongList(CDInfo);
}

void MainWindow::PopulateSongList(CDINFO CDInfo)
{
    CDInfo.index = 0;
    if(CDInfo.songList.count() > 0)
        ui->bSonga->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSonga->setText("");
    if(CDInfo.songList.count() > 1)
        ui->bSongb->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongb->setText("");
    if(CDInfo.songList.count() > 2)
        ui->bSongc->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongc->setText("");
    if(CDInfo.songList.count() > 3)
        ui->bSongd->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongd->setText("");
    if(CDInfo.songList.count() > 4)
        ui->bSonge->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSonge->setText("");
    if(CDInfo.songList.count() > 5)
        ui->bSongf->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongf->setText("");
    if(CDInfo.songList.count() > 6)
        ui->bSongg->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongg->setText("");
    if(CDInfo.songList.count() > 7)
        ui->bSongh->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongh->setText("");
    if(CDInfo.songList.count() > 8)
        ui->bSongi->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongi->setText("");
    if(CDInfo.songList.count() > 9)
        ui->bSongj->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongj->setText("");
    if(CDInfo.songList.count() > 10)
        ui->bSongk->setText(CDInfo.songList.at(CDInfo.index++));
    else
        ui->bSongk->setText("");
    if(CDInfo.songList.count() > 11)
        ui->bSongl->setText(CDInfo.songList.at(CDInfo.index));
    else
        ui->bSongl->setText("");
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_SONGSELECT);

}
void MainWindow::on_bSonga_clicked(){
     songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr) + ".mp3"));
     ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongb_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 1) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongc_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 2) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongd_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 3) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSonge_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 4) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongf_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 5) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongg_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 6) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongh_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 7) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongi_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 8) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongj_clicked(){
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 9) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}
void MainWindow::on_bSongk_clicked()
{
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 10) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}

void MainWindow::on_bSongl_clicked()
{
    songQueue.append(QString(CDInfo.filePath + "/" + CDInfo.songList.at(CDInfo.indexPtr + 11) + ".mp3"));
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}

void MainWindow::on_bSongUp_clicked()
{

    if(CDInfo.numberOfSongs > NUM_SELECT_SONGS){
        if(CDInfo.indexPtr > 0){
            CDInfo.index = --CDInfo.indexPtr;
            if(CDInfo.songList.count() > 0)
                ui->bSonga->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSonga->setText("");
            if(CDInfo.songList.count() > 1)
                ui->bSongb->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongb->setText("");
            if(CDInfo.songList.count() > 2)
                ui->bSongc->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongc->setText("");
            if(CDInfo.songList.count() > 3)
                ui->bSongd->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongd->setText("");
            if(CDInfo.songList.count() > 4)
                ui->bSonge->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSonge->setText("");
            if(CDInfo.songList.count() > 5)
                ui->bSongf->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongf->setText("");
            if(CDInfo.songList.count() > 6)
                ui->bSongg->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongg->setText("");
            if(CDInfo.songList.count() > 7)
                ui->bSongh->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongh->setText("");
            if(CDInfo.songList.count() > 8)
                ui->bSongi->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongi->setText("");
            if(CDInfo.songList.count() > 9)
                ui->bSongj->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongj->setText("");
            if(CDInfo.songList.count() > 10)
                ui->bSongk->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongk->setText("");
            if(CDInfo.songList.count() > 11)
                ui->bSongl->setText(CDInfo.songList.at(CDInfo.index));
            else
                ui->bSongl->setText("");
        }
    }
}

void MainWindow::on_bSongDn_clicked()
{

    if(CDInfo.numberOfSongs > NUM_SELECT_SONGS){
        if( (CDInfo.indexPtr + NUM_SELECT_SONGS) < CDInfo.numberOfSongs){
            CDInfo.index = ++CDInfo.indexPtr;
            if(CDInfo.songList.count() > 0)
                ui->bSonga->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSonga->setText("");
            if(CDInfo.songList.count() > 1)
                ui->bSongb->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongb->setText("");
            if(CDInfo.songList.count() > 2)
                ui->bSongc->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongc->setText("");
            if(CDInfo.songList.count() > 3)
                ui->bSongd->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongd->setText("");
            if(CDInfo.songList.count() > 4)
                ui->bSonge->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSonge->setText("");
            if(CDInfo.songList.count() > 5)
                ui->bSongf->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongf->setText("");
            if(CDInfo.songList.count() > 6)
                ui->bSongg->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongg->setText("");
            if(CDInfo.songList.count() > 7)
                ui->bSongh->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongh->setText("");
            if(CDInfo.songList.count() > 8)
                ui->bSongi->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongi->setText("");
            if(CDInfo.songList.count() > 9)
                ui->bSongj->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongj->setText("");
            if(CDInfo.songList.count() > 10)
                ui->bSongk->setText(CDInfo.songList.at(CDInfo.index++));
            else
                ui->bSongk->setText("");
            if(CDInfo.songList.count() > 11)
                ui->bSongl->setText(CDInfo.songList.at(CDInfo.index));
            else
                ui->bSongl->setText("");
        }
    }
}


void MainWindow::on_bSongSelBack_clicked()
{
    ui->JukeboxWidgets->setCurrentIndex(MEDIA_CDSELECT);
}







void MainWindow::on_vsPreamp_valueChanged(int value)
{
    mp->equ.setPreamp((float) value);
    EquUpdateVals();
}

void MainWindow::on_vsBand1_valueChanged(int value)
{
    mp->equ.setBand((float) value, 0);
    EquUpdateVals();
}

void MainWindow::on_vsBand2_valueChanged(int value)
{
     mp->equ.setBand((float) value, 1);
     EquUpdateVals();
}

void MainWindow::on_vsBand3_valueChanged(int value)
{
     mp->equ.setBand((float) value, 2);
     EquUpdateVals();
}

void MainWindow::on_vsBand4_valueChanged(int value)
{
     mp->equ.setBand((float) value, 3);
     EquUpdateVals();
}

void MainWindow::on_vsBand5_valueChanged(int value)
{
     mp->equ.setBand((float) value, 4);
     EquUpdateVals();
}

void MainWindow::on_vsBand6_valueChanged(int value)
{
     mp->equ.setBand((float) value, 5);
     EquUpdateVals();
}

void MainWindow::on_vsBand7_valueChanged(int value)
{
     mp->equ.setBand((float) value, 6);
     EquUpdateVals();
}

void MainWindow::on_vsBand8_valueChanged(int value)
{
     mp->equ.setBand((float) value, 7);
     EquUpdateVals();
}

void MainWindow::on_vsBand9_valueChanged(int value)
{
     mp->equ.setBand((float) value, 8);
     EquUpdateVals();
}

void MainWindow::on_vsBand10_valueChanged(int value)
{
     mp->equ.setBand((float) value, 9);
     EquUpdateVals();
}

void MainWindow::on_cbEqPresets_currentIndexChanged(int index)
{
    qDebug() << index;
     mp->equ.setPreset(index);
     EquUpdateVals();
}

void MainWindow::on_bSkip_clicked()
{
    mp->stopSong();
}

#include "mainwindow.h"
#include <QApplication>
#include "mediaplayer.h"
//#include "vlc-qt/WidgetVideo.h"
#include "mediaplayer.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    return a.exec();
}

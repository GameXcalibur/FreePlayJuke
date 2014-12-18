#ifndef FILEIO_H
#define FILEIO_H

#include <QDir>

class fileIO
{
public:
    fileIO();

    QStringList GetCDList(QString );
    QStringList GetSongList(QString );
    void CreateFolders(void);



private:
    QDir mediaDir;
};


#endif // FILEIO_H

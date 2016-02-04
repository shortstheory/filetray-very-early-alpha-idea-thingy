#include "cutthread.h"
#include <QStringList>
#include <QString>
#include <QFile>
cutThread::cutThread()
{
    finished = false;
}

cutThread::~cutThread()
{
}

void cutThread::run()
{
    qint64 i;
    QString temp;
    for(i = 0; i < selectedFiles.size(); i++)
    {
        temp = selectedFolder + fileRootName(selectedFiles.at(i));
        QFile::copy(selectedFiles.at(i), temp);
    }
    for(i = 0; i < selectedFiles.size(); i++)
    {
        QFile::remove(selectedFiles.at(i));
    }
}

QString cutThread::fileRootName(QString fileName)
{
    int i = fileName.length();
    while(fileName[i--] != '/');
    return fileName.mid(i+1, fileName.length() - (i+1));
}

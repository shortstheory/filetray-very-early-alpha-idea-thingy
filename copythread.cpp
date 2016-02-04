#include "copythread.h"
#include <QFile>

copyThread::copyThread()
{
    finished = false;
}

copyThread::~copyThread()
{
}

void copyThread::run()
{
    qint64 i;
    QString temp;
    for(i = 0; i < selectedFiles.size(); i++)
    {
        temp = selectedFolder + fileRootName(selectedFiles.at(i));
        QFile::copy(selectedFiles.at(i), temp);
    }
    finished = true;
}

QString copyThread::fileRootName(QString fileName)
{
    int i = fileName.length();
    while(fileName[i--] != '/');
    return fileName.mid(i+1, fileName.length() - (i+1));
}

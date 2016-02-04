#include <QThread>
#include <QStringList>
#include <QString>
#ifndef COPYTHREAD_H
#define COPYTHREAD_H

class copyThread : public QThread
{
public:
    copyThread();
    ~copyThread();
    QStringList selectedFiles;
    QString selectedFolder;
    QString fileRootName(QString);
    void run();
    bool finished;
};


#endif // COPYTHREAD_H

#include <QThread>
#include <QStringList>
#include <QString>
#ifndef CUTTHREAD_H
#define CUTTHREAD_H

class cutThread: public QThread
{
public:
public:
    cutThread();
    ~cutThread();
    QStringList selectedFiles;
    QString selectedFolder;
    QString fileRootName(QString);
    void run();
    bool finished;
};

#endif // CUTTHREAD_H

#ifndef THREADTEST_H
#define THREADTEST_H

#include <QThread>

class threadTest : public QThread
{
    Q_OBJECT
public:
    explicit threadTest(QObject *parent = 0);

signals:

public slots:

};

#endif // THREADTEST_H

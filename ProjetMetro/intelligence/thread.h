#ifndef THREAD_H
#define THREAD_H

#include "../main.h"

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
    void run() ;

signals:
    void globalRefreshSlot() ;

public slots:
     void globalRefresh() ;

};

#endif // THREAD_H

#ifndef THREAD_H
#define THREAD_H

#include "../main.h"

class Thread : public QThread
{
public:
    Thread();
    void run() ;
};

#endif // THREAD_H

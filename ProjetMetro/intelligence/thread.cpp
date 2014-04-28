#include "../main.h"

Thread::Thread()
{
}

void Thread::run(){
    connect(this, SIGNAL(globalRefresh()), this, SLOT(globalRefreshSlot()));
    Intelligence::run() ;
}


void Thread::globalRefreshSlot(){
    Window::main->refreshArcs() ;
}

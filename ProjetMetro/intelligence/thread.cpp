#include "../main.h"

Thread::Thread()
{
}

void Thread::run(){
    connect(this, SIGNAL(pheromonesChanged()), Window::main, SLOT(refreshSlot()));
    Intelligence::run() ;
}

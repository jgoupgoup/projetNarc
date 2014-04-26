#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

#include "../main.h"

class Intelligence
{
public:
    Intelligence();
    void creationFourmis(int nbFourmis);
    static void run();
    static void runTest();
    static void launch();
    static Thread t ;

};
#endif // INTELLIGENCE_H

#ifndef DATALOAD_H
#define DATALOAD_H

#include "../main.h"

class DataLoad
{

private:
    DataLoad();
    static void arcs() ;
    static void tops() ;
    static void tracks() ;
    static void preciseArcs() ;

public:
    static void go() ;

};

#endif // DATALOAD_H

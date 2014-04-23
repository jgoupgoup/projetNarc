#include "main.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    DataLoad::tops() ;
    DataLoad::arcs() ;
    DataLoad::tracks() ;
    DataLoad::preciseArcs() ;

    QApplication a(argc, argv);
    Window w;
    w.show();



    return a.exec();
}

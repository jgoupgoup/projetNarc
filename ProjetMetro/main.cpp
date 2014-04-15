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

    Narc::getById(0)->setPheromone(0.1) ;
    Narc::getById(0)->setPheromone(0.2) ;
    Narc::getById(0)->setPheromone(0.3) ;
    Narc::getById(0)->setPheromone(0.4) ;
    Narc::getById(0)->setPheromone(0.5) ;
    Narc::getById(0)->setPheromone(0.6) ;

    Window::main->refreshArcs() ;

    return a.exec();
}

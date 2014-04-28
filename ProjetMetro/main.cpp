#include "main.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    DataLoad::go() ;

    //Pour l'initialisation du random
    srand(time(NULL));

    QApplication a(argc, argv);
    Window w;
    w.show();



    return a.exec();
}


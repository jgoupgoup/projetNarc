#include "main.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    DataLoad::go() ;

    QApplication a(argc, argv);
    Window w;
    w.show();



    return a.exec();
}


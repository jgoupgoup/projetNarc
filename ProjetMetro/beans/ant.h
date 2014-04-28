#ifndef ANT_H
#define ANT_H

#include "../main.h"

class Ant
{
private:
    int id;
    string name;
    QVector<Narc*> visitedArcs;


public:
    //Constructeur
    Ant();

    //Variables globales
    static QVector<Ant*> list;
    static QVector<Ant*> getList() ;
    static void resetAll() ;

    Top* currentTop ;

    //Methodes
    int getId();

    string getName();
    void setName(string name);
    Ant* reset();
    Ant* setCurrentTop(Top* currentTop);
    Top* getCurrentTop();
    QVector<Narc*> getVisitedArcs();
    QVector<Narc*> getListAroundUnvisitedNarcs();
    QVector<Narc*> getListAroundNarcs();

    Ant* goThrough(Narc* arc) ;
};

#endif // ANT_H

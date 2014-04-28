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
    static float bestPathLength ;

    Top* currentTop ;

    //Methodes
    int getId();

    string getName();
    void setName(string name);
    Ant* reset();
    Ant* setCurrentTop(Top* currentTop);
    Top* getCurrentTop();
    QVector<Narc*> getVisitedArcs();
    QVector<Narc*> removeVisitedNarcs(QVector<Narc*> list) ;
    QVector<Narc*> getListAroundNarcs();

    Ant* goThrough(Narc* arc) ;
    Narc* chooseNarc() ;
    Narc* pickUp(QVector<Narc*> list) ;

    float getPathLength() ;
    float getPheromonesIncrement() ;

    Narc* getRollBackNarc() ;
    QVector<Narc*> removeRollbackNarc(QVector<Narc*> narcs) ;
    QVector<Narc*> removeDisabledNarcs(QVector<Narc*> narcsChoosable) ;
};

#endif // ANT_H

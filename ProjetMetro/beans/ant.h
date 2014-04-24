#ifndef ANT_H
#define ANT_H

#include "../main.h"

class Ant
{
private:
    int id;
    string name;
    vector<Narc*> visitedArcs;


public:
    //Constructeur
    Ant();

    //Variables globales
    static vector<Ant*> list;
    static vector<Ant*> getList() ;
    static void resetAll() ;

    Top* currentTop ;

    //Methodes
    int getId();

    string getName();
    void setName(string name);
    Ant* reset();
    Ant* setCurrentTop(Top* currentTop);
    Top* getCurrentTop();
    vector<Narc*> getVisitedArcs();
    vector<Narc*> getListAroundUnvisitedNarcs();
    vector<Narc*> getListAroundNarcs();
};

#endif // ANT_H

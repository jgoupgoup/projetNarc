#ifndef TOP_H
#define TOP_H

#include "../main.h"

class Top
{
private:
    int id;
    string name;
    float x;
    float y;
    TopGraphic* graphic ;

public:
    //Constructeur
    Top(int id);

    //Variables globales
    static vector<Top*> list;
    static vector<Top*> getList();
    static Top* getById(int id);

    //Methodes
    int getId();

    string getName();
    Top* setName(string name);

    float getX();
    Top* setX(float x);

    float getY();
    Top* setY(float y);

    TopGraphic* getGraphic();
    Top* setGraphic(TopGraphic* topGraphic);
};

#endif // TOP_H

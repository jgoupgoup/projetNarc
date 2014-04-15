#ifndef TRACK_H
#define TRACK_H

#include "../main.h"

class Track
{
private:
    string id;
    vector<Narc*> arcs;
    QColor color;

public:
    //Constructeur
    Track(string id);

    //Variables globales
    static vector<Track*> list;
    static vector<Track*> getList();
    static Track* getById(string id) ;

    //Methodes
    string getId();

    QColor getColor();
    Track* setColor(QColor color);

};

#endif // TRACK_H

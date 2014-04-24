#ifndef ARC_H
#define ARC_H

#include "../main.h"

class Narc
{
private:
    int id;
    Top* startTop;
    Top* endTop;
    float weight;
    float pheromone;
    bool availability ;
    NarcGraphic* graphic ;
    Track* track ;
    float score;

public:
    //Constructeur
    Narc();

    // Methodes globales
    static vector<Narc*> getList();
    static Narc* getById(int id);

    //Variables globales, en static
    static vector<Narc*> list;


    //Methodes
    int getId();

    Top* getStartTop();
    Narc* setStartTop(Top* startTop);

    Top* getEndTop();
    Narc* setEndTop(Top* endTop);

    bool getAvailability();
    Narc* setAvailability(bool availability);

    float getWeight();
    Narc* setWeight(float weight);

    float getPheromone();
    Narc* setPheromone(float pheromone);

    Track* getTrack();
    Narc* setTrack(Track* track);

    NarcGraphic* getGraphic();
    Narc* setGraphic(NarcGraphic* arcGraphic);

    Narc* getInverseArc() ;

    Narc* getBestNarcFrom(vector<Narc*> listOfNarcs);
    Narc* getScore(Narc* narc);
};

#endif // ARC_H

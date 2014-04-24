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

    static Narc* weightestNarc ;
    static Narc* mostPheromonedNarc ;

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

    static Narc* getWeightestNarc() ;
    static void setWeightestNarc(Narc* arc) ;
    static void defineWeightestNarc() ;

    static Narc* getMostPheromonedNarc() ;
    static void setMostPheromonedNarc(Narc* arc) ;
};

#endif // ARC_H

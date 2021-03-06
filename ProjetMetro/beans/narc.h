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

    static Narc* weightestNarc ;
    static Narc* mostPheromonedNarc ;

public:
    //Constructeur
    Narc();

    // Methodes globales
    static QVector<Narc*> getList();
    static Narc* getById(int id);

    //Variables globales, en static
    static QVector<Narc*> list;


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


    Narc* setScore(float score) ;
    float getScore() ;

    Narc* getInverseArc() ;
    Narc* evaluate() ;

    static Narc* getWeightestNarc() ;
    static void setWeightestNarc(Narc* arc) ;
    static void defineWeightestNarc() ;

    static Narc* getMostPheromonedNarc() ;
    static void setMostPheromonedNarc(Narc* arc) ;

    static Narc* getBestNarcFrom(QVector<Narc*> listOfNarcs);

    static Narc* pickUp(QVector<Narc*> list) ;
};

#endif // ARC_H

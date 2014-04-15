#ifndef PARAMETERS_H
#define PARAMETERS_H

class Parameters
{

private:
    static Top* startTop ;
    static Top* endTop ;

    static bool applicationStarted ;

    static Top* hoveredTop ;
    static Narc* hoveredNarc ;
    static Narc* activeNarc ;


public:
    Parameters();

    static Top* getStartTop() ;
    static void setStartTop(Top* top) ;

    static Top* getEndTop() ;
    static void setEndTop(Top* top) ;

    static Top* getHoveredTop() ;
    static void setHoveredTop(Top* top) ;

    static Narc* getHoveredNarc() ;
    static void setHoveredNarc(Narc* arc) ;

    static Narc* getActiveNarc() ;
    static void setActiveNarc(Narc* arc) ;

    static bool isApplicationStarted() ;
    static void switchApplicationStartState() ;

} ;
#endif // PARAMETERS_H

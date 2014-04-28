#include "../main.h"

bool Parameters::applicationStarted = false ;
float Parameters::phermomonesIncrement = 1 ;
float Parameters::phermomonesDecrement = 0.002 ;

QMutex Parameters::mutex ;
QWaitCondition Parameters::condition ;

Top* Parameters::startTop = NULL ;
Top* Parameters::endTop = NULL ;
Top* Parameters::hoveredTop = NULL ;
Narc* Parameters::hoveredNarc = NULL ;
Narc* Parameters::activeNarc = NULL ;

Parameters::Parameters(){}

float Parameters::random(float min, float max)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}


Top* Parameters::getStartTop(){ return(Parameters::startTop) ; }
void Parameters::setStartTop(Top* top){ Parameters::startTop = top ; }

Top* Parameters::getEndTop(){ return(Parameters::endTop) ; }
void Parameters::setEndTop(Top* top){ Parameters::endTop = top ; }

Top* Parameters::getHoveredTop(){ return(Parameters::hoveredTop) ; }
void Parameters::setHoveredTop(Top* top){ Parameters::hoveredTop = top ; }

Narc* Parameters::getHoveredNarc(){ return(Parameters::hoveredNarc) ; }
void Parameters::setHoveredNarc(Narc* arc){ Parameters::hoveredNarc = arc ; }

Narc* Parameters::getActiveNarc(){ return(Parameters::activeNarc) ; }
void Parameters::setActiveNarc(Narc* arc){ Parameters::activeNarc = arc ; }

bool Parameters::isApplicationStarted(){ return(Parameters::applicationStarted) ; }
void Parameters::switchApplicationStartState(){ Parameters::applicationStarted = !Parameters::applicationStarted ; }

float Parameters::getPheromonesIncrement(){ return(Parameters::phermomonesIncrement) ; }
float Parameters::getPheromonesDecrement(){ return(Parameters::phermomonesDecrement) ; }

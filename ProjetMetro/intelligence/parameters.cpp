#include "../main.h"

bool Parameters::applicationStarted = false ;

Top* Parameters::startTop = NULL ;
Top* Parameters::endTop = NULL ;
Top* Parameters::hoveredTop = NULL ;
Narc* Parameters::hoveredNarc = NULL ;
Narc* Parameters::activeNarc = NULL ;

Parameters::Parameters(){}

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

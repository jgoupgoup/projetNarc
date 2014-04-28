#include "../main.h"

QVector<Ant*> Ant::list;
QVector<Ant*> Ant::getList(){ return Ant::list; }

Ant::Ant() {
    this->id = list.size();
    this->setCurrentTop(Parameters::getStartTop()) ;
    this->list.push_back(this);
}

void Ant::resetAll(){
    for(unsigned int i = 0 ; i < Ant::list.size() ; i++){
        Ant* ant = Ant::list[i] ;
        ant->reset() ;
    }
}

int Ant::getId(){ return(this->id); }

string Ant::getName(){ return(this->name) ; }
void Ant::setName(string name){ this->name = name ; }

Ant* Ant::goThrough(Narc* arc){
    this->visitedArcs.push_back(arc);
    this->setCurrentTop(arc->getEndTop()) ;
    cout << "Arc traversé : "
         << arc->getId()
         << " depuis "
         << arc->getStartTop()->getName()
         << " vers "
         << arc->getEndTop()->getName()
         << " sur la ligne "
         << arc->getTrack()->getId()
         << endl ;
    return(this) ;
}


QVector<Narc*> Ant::getVisitedArcs(){ return this->visitedArcs; }


Ant* Ant::reset(){
    this->setCurrentTop(Parameters::getStartTop());
    return this;
}
Top* Ant::getCurrentTop(){ return(this->currentTop);}
Ant* Ant::setCurrentTop(Top* currentTop){
    this->currentTop = currentTop;
    return this;
}
QVector<Narc*> Ant::getListAroundUnvisitedNarcs(){
    QVector<Narc*> listAroundUnvisitedNarcs ;
    QVector<Narc*> listAroundNarcs = this->getListAroundNarcs();
    bool alreadyVisited = false ;

    for(unsigned int i=0; i<listAroundNarcs.size(); i++){
        Narc* narcAround = listAroundNarcs[i];
        alreadyVisited = false ;

        for(unsigned int j=0; j<this->getVisitedArcs().size(); j++){
            Narc* narcVisited = this->getVisitedArcs()[j];
            if(narcAround == narcVisited){
                alreadyVisited = true ;
                break ;
            }
        }

        if(alreadyVisited == false)
            listAroundUnvisitedNarcs.push_back(narcAround);

    }
    cout << " and " << listAroundUnvisitedNarcs.size() << " are not visited" << endl ;
    return listAroundUnvisitedNarcs;
}
QVector<Narc*> Ant::getListAroundNarcs(){
    QVector<Narc*> listAroundNarcs;
    for(unsigned int k=0; k<Narc::list.size(); k++){
        Narc* narc = Narc::list[k];
        if(this->getCurrentTop() == narc->getStartTop()){
            listAroundNarcs.push_back(narc);
        }
    }
    cout << listAroundNarcs.size() << " narcs around me";
    return listAroundNarcs;
}

#include "../main.h"

vector<Ant*> Ant::list;
vector<Ant*> Ant::getList(){ return Ant::list; }

Ant::Ant() {
    this->id = list.size();
    this->list.push_back(this);
}

void Ant::resetAll(){
    for(int i = 0 ; i < Ant::list.size() ; i++){
        Ant* ant = Ant::list[i] ;
        //ant->reset() ;
    }
}

int Ant::getId(){ return(this->id); }

string Ant::getName(){ return(this->name) ; }
void Ant::setName(string name){ this->name = name ; }

vector<Narc*> Ant::getVisitedArcs(){ return this->visitedArcs; }


Ant* Ant::reset(){
    this->setCurrentTop(Parameters::getStartTop());
    return this;
}
Top* Ant::getCurrentTop(){ return(this->currentTop);}
Ant* Ant::setCurrentTop(Top* currentTop){
    this->currentTop = currentTop;
    return this;
}
vector<Narc*> Ant::listAroundUnvisitedNarcs(){
    vector<Narc*> listAroundUnvisitedNarcs;
    vector<Narc*> listAroundNarcs = this->getListAroundNarcs();
    for(int i=0; i<listAroundNarcs.size(); i++){
        Narc* narcAround = Narc::list[i];
        for(int j=0; j<this->getVisitedArcs().size(); j++){
            Narc* narcUnvisited = Narc::list[j];
            if(narcAround != narcUnvisited)
                listAroundUnvisitedNarcs.push_back(narcAround);
        }
    }
    return listAroundUnvisitedNarcs;
}
vector<Narc*> Ant::getListAroundNarcs(){
    vector<Narc*> listAroundNarcs;
    for(int k=0; k<Narc::list.size(); k++){
        Narc* narc = Narc::list[k];
        if(this->getCurrentTop() == narc->getStartTop())
            listAroundNarcs.push_back(narc);
    }
    return listAroundNarcs;
}

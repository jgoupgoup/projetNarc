#include "../main.h"

QVector<Ant*> Ant::list;
QVector<Ant*> Ant::getList(){ return Ant::list; }
float Ant::bestPathLength = 0 ;

Ant::Ant() {
    this->id = list.size();
    this->setCurrentTop(Parameters::getStartTop()) ;
    this->list.push_back(this);
}

void Ant::resetAll(){
    for( int i = 0 ; i < Ant::list.size() ; i++){
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
    return(this) ;
}


QVector<Narc*> Ant::getVisitedArcs(){ return this->visitedArcs; }


Ant* Ant::reset(){
    this->setCurrentTop(Parameters::getStartTop());
    this->visitedArcs.clear();
    //cout << "===================================================================" << endl;
    return this;
}
Top* Ant::getCurrentTop(){ return(this->currentTop);}
Ant* Ant::setCurrentTop(Top* currentTop){
    this->currentTop = currentTop;
    return this;
}
QVector<Narc*> Ant::removeVisitedNarcs(QVector<Narc*> list){
    QVector<Narc*> listAroundUnvisitedNarcs ;
    QVector<Narc*> listAroundNarcs = list;
    bool alreadyVisited = false ;

    for( int i=0; i<listAroundNarcs.size(); i++){
        Narc* narcAround = listAroundNarcs[i];
        alreadyVisited = false ;

        for( int j=0; j<this->getVisitedArcs().size(); j++){
            Narc* narcVisited = this->getVisitedArcs()[j];
            if(narcAround == narcVisited){
                alreadyVisited = true ;
                break ;
            }
        }

        if(alreadyVisited == false)
            listAroundUnvisitedNarcs.push_back(narcAround);

    }
    //cout << " and " << listAroundUnvisitedNarcs.size() << " are not visited" << endl ;
    return listAroundUnvisitedNarcs;
}
QVector<Narc*> Ant::getListAroundNarcs(){
    QVector<Narc*> listAroundNarcs;
    for( int k=0; k<Narc::list.size(); k++){
        Narc* narc = Narc::list[k];
        if(this->getCurrentTop() == narc->getStartTop()){
            listAroundNarcs.push_back(narc);
        }
    }
    //cout << listAroundNarcs.size() << " narcs around me";
    return listAroundNarcs;
}


Narc* Ant::getRollBackNarc(){
    // Si on a pas parcouru de narcs, on a pas de rollback à enlever
    if(this->getVisitedArcs().size() == 0) return(NULL) ;

    // Si le dernier narcs parcouru est en sens unique, on a pas de narcs à enlever
    Narc* lastNarc = this->getVisitedArcs().last() ;
    if(lastNarc->getInverseArc() == NULL) return(NULL) ;

    return(lastNarc->getInverseArc()) ;
}

QVector<Narc*> Ant::removeRollbackNarc(QVector<Narc*> narcs){
    Narc* rollbackNarc = this->getRollBackNarc() ;

    if(rollbackNarc == NULL) return(narcs) ;

    // Si le rollbackNarc n'est pas dans la liste, on a rien à enlever
    if(narcs.indexOf(rollbackNarc) ==  -1) return(narcs) ;

    // Sinon, on va enlever le rollbackNarc
    narcs.remove(narcs.indexOf(rollbackNarc)) ;
    return(narcs) ;

}

QVector<Narc*> Ant::removeDisabledNarcs(QVector<Narc*> narcsChoosable){
   QVector<Narc*> ret ;
   for(int i = 0 ; i < narcsChoosable.size() ; i++){
       if(narcsChoosable[i]->getAvailability()) ret.push_back(narcsChoosable[i]);
   }
   return(ret) ;
}


Narc* Ant::chooseNarc(){
    QVector<Narc*> narcsChoosable = this->getListAroundNarcs() ;
    narcsChoosable = this->removeDisabledNarcs(narcsChoosable) ;
    narcsChoosable = this->removeVisitedNarcs(narcsChoosable) ;
    narcsChoosable = this->removeRollbackNarc(narcsChoosable) ;


    if(narcsChoosable.size() == 0){
        Narc* rollbackNarc = this->getRollBackNarc() ;
        if(rollbackNarc == NULL) return(NULL) ;
        else if(this->getVisitedArcs().contains(rollbackNarc)) return(NULL) ;
        else return(rollbackNarc) ;
    }

    // Le rollback n'est plus dans les narcsChoosable

    Narc* ret = Narc::getBestNarcFrom(narcsChoosable) ;
    return(ret) ;
}

float Ant::getPathLength(){
    float ret = 0 ;
    for(int i = 0 ; i < this->getVisitedArcs().size() ; i++)
        ret += this->getVisitedArcs()[i]->getWeight() ;
    return(ret) ;
}

float Ant::getPheromonesIncrement(){
    float pathLength = this->getPathLength() ;
    if(Ant::bestPathLength == 0){
        Ant::bestPathLength = pathLength ;
        return(Parameters::getPheromonesIncrement()) ;
    }

    if(pathLength < Ant::bestPathLength) Ant::bestPathLength = pathLength ;
    float ret = (Ant::bestPathLength / pathLength) * Parameters::getPheromonesIncrement() ;
    if(pathLength > Ant::bestPathLength) ret /= 1000 ;
    return(ret) ;
}


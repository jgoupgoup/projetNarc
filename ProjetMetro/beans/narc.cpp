#include "../main.h"

vector<Narc*> Narc::list;
vector<Narc*> Narc::getList(){ return Narc::list; }
Narc* Narc::getById(int id){
    vector<Narc*> list = Narc::getList() ;
    for(int i = 0 ; i < list.size() ; i++){
        Narc* arc = list[i] ;
        if(arc->getId() == id) return(arc) ;
    }
}

Narc::Narc(){
    this->id = list.size();
    this->setAvailability(true) ;
    this->setPheromone(0) ;
    Narc::list.push_back(this);
}
int Narc::getId(){ return(this->id);}

Top* Narc::getStartTop(){ return(this->startTop); }
Narc* Narc::setStartTop(Top* startTop){ this->startTop = startTop ; return(this) ; }

Top* Narc::getEndTop(){ return(this->endTop); }
Narc* Narc::setEndTop(Top* endTop){ this->endTop = endTop ; return(this) ; }

bool Narc::getAvailability(){ return(this->availability) ; }
Narc* Narc::setAvailability(bool availability){ this->availability = availability ; return(this) ; }

float Narc::getWeight(){ return(this->weight);}
Narc* Narc::setWeight(float weight){ this->weight = weight ; return(this) ; }

Track* Narc::getTrack(){ return(this->track);}
Narc* Narc::setTrack(Track* track){ this->track = track ; return(this) ; }

float Narc::getPheromone(){ return(this->pheromone);}
Narc* Narc::setPheromone(float pheromone){ this->pheromone = pheromone ; return(this) ; }

NarcGraphic* Narc::getGraphic(){ return(this->graphic) ; }
Narc* Narc::setGraphic(NarcGraphic* arcGraphic){ this->graphic = arcGraphic ; return(this) ; }

Narc* Narc::getInverseArc(){
    vector<Narc*> list = Narc::getList() ;
    for(int i = 0 ; i < list.size() ; i++ ) {
        Narc* arc = list[i] ;
        if(arc->getEndTop() == this->getStartTop()){
            if(arc->getStartTop() == this->getEndTop())
                return(arc) ;
        }
    }
    return(NULL) ;
}

Narc* Narc::getBestNarcFrom(vector<Narc*> listOfNarcs){
    //On choisi le premier narc de la liste comme élu
    Arc* narcChoosed = listOfNarcs[0];

    //On parcours le reste de la liste
    for(int k=1 ; k < listOfNarcs.size() ; k++){
        //on vérifie si l'arc en question n'est pas meilleur à choisir
        Narc* narcEnCours = listOfNarcs[k];
        if(narcEnCours.getScore() > narcChoosed.getScore())
            //si c'est le cas, on le prend
            narcChoosed = narcEnCours;
        }
    return(narcChoosed);
}

Narc* Narc::getScore(Narc* narc){
    float poidsNarc = (Narc::getWeightestNarc() - this->getWeight()) / Narc::getWeightestNarc();
    float pheromoneNarc = this->getPheromone() / Narc::getMostPheromonedNarc();
    float scoreNarc = (poidsNarc + pheromoneNarc) /2;
    this->score = scoreNarc;

    return(this);
}

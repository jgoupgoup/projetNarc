#include "../main.h"

vector<Track*> Track::list;
vector<Track*> Track::getList(){ return Track::list; }
Track* Track::getById(string id){
    vector<Track*> list = Track::getList() ;
    for(int i = 0 ; i < list.size() ; i++){
        Track* track = list[i] ;
        if(track->getId() == id) return(track) ;
    }
}

Track::Track(string id){
    this->id = id ;
    this->list.push_back(this) ;
}

string Track::getId(){ return(this->id); }

QColor Track::getColor(){ return(this->color); }
Track* Track::setColor(QColor color){ this->color = color ; return(this) ; }


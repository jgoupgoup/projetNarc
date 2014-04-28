#include "../main.h"

QVector<Track*> Track::list;
QVector<Track*> Track::getList(){ return Track::list; }
Track* Track::getById(string id){
    QVector<Track*> list = Track::getList() ;
    for( int i = 0 ; i < list.size() ; i++){
        Track* track = list[i] ;
        if(track->getId() == id) return(track) ;
    }
    return(NULL) ;
}

Track::Track(string id){
    this->id = id ;
    this->list.push_back(this) ;
}

string Track::getId(){ return(this->id); }

QColor Track::getColor(){ return(this->color); }
Track* Track::setColor(QColor color){ this->color = color ; return(this) ; }


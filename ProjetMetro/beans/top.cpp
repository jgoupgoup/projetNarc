#include "../main.h"

// Static
QVector<Top*> Top::list;
QVector<Top*> Top::getList(){ return Top::list; }
Top* Top::getById(int id){
    QVector<Top*> list = Top::getList() ;
    for( int i = 0 ; i < list.size() ; i++){
        Top* top = list[i] ;
        if(top->getId() == id) return(top) ;
    }
    return(NULL) ;
}

// Instance
Top::Top(int id) {
    this->id = id;
    this->list.push_back(this);
}

int Top::getId(){ return(this->id); }

string Top::getName(){ return(this->name); }
Top* Top::setName(string name){ this->name = name ; return(this) ; }

float Top::getX(){ return(this->x); }
Top* Top::setX(float x){ this->x = x ; return(this) ; }

float Top::getY(){ return(this->y); }
Top* Top::setY(float y){ this->y = y ; return(this) ; }

TopGraphic* Top::getGraphic(){ return(this->graphic) ; }
Top* Top::setGraphic(TopGraphic* topGraphic){ this->graphic = topGraphic ; return(this) ; }


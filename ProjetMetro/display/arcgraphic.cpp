#include "../main.h"

float  NarcGraphic::minThickness = 1 ;
float  NarcGraphic::maxThickness = 6 ;

QColor NarcGraphic::disabledColor = QColor::fromRgbF(0,0,0,0.70) ;
QColor NarcGraphic::hoverColor = QColor::fromRgbF(0,0,0.666,1) ;


NarcGraphic::NarcGraphic(float startX, float startY, float endX, float endY) :
    QGraphicsLineItem(
        (qreal)startX,
        (qreal)startY,
        (qreal)endX,
        (qreal)endY){
    this->setThickness(NarcGraphic::minThickness) ;
    this->setAcceptHoverEvents(true);
    this->setCursor(Qt::PointingHandCursor);
}

NarcGraphic* NarcGraphic::setArc(Narc* arc){
    this->arc = arc ;
    arc->setGraphic(this) ;
}

Narc* NarcGraphic::getArc(){ return(this->arc) ; }


NarcGraphic* NarcGraphic::setThickness(float thickness){
    this->thickness = thickness ;
}

float NarcGraphic::getThickness(){
    return(this->thickness) ;
}

void NarcGraphic::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Parameters::setActiveNarc(this->getArc()) ;
    Window::main->refreshVoies() ;
}

void NarcGraphic::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    //Parameters::setHoveredNarc(this->getArc()) ;
    //Window::main->refreshArcs() ;
}

void NarcGraphic::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    //Parameters::setHoveredNarc(NULL) ;
    //Window::main->refreshArcs() ;
}


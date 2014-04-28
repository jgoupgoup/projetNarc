#include "../main.h"

float  TopGraphic::size = 7 ;

QColor TopGraphic::defaultBackColor = QColor::fromRgbF(0,0,0,0.1) ;
QColor TopGraphic::defaultBorderColor = QColor::fromRgbF(0.5,0.5,0.5,1) ;
float  TopGraphic::defaultBorderThickness = 0.1 ;

QColor TopGraphic::startBackColor = QColor::fromRgbF(0,0.666,0,1) ;
QColor TopGraphic::startBorderColor = QColor::fromRgbF(0,0.666,0,0.8) ;
float  TopGraphic::startBorderThickness = 10 ;

QColor TopGraphic::endBackColor = QColor::fromRgbF(0.666,0,0,1) ;
QColor TopGraphic::endBorderColor = QColor::fromRgbF(0.666,0,0,0.8) ;
float  TopGraphic::endBorderThickness = 10 ;

QColor TopGraphic::hoverBackColor = QColor::fromRgbF(0,0,0.666,1) ;
QColor TopGraphic::hoverBorderColor = QColor::fromRgbF(0,0,1,1) ;
float  TopGraphic::hoverBorderThickness = 0.1 ;

TopGraphic::TopGraphic(float x, float y) :
    QGraphicsEllipseItem(
        (qreal)x,
        (qreal)y,
        (qreal)TopGraphic::size,
        (qreal)TopGraphic::size){
    this->x = x ;
    this->y = y ;
    this->setAcceptHoverEvents(true);
    this->setCursor(Qt::ArrowCursor);
}

float TopGraphic::getX(){ return(this->x) ; }
float TopGraphic::getY(){ return(this->y) ; }

TopGraphic* TopGraphic::setTop(Top* top){
    this->top  = top ;
    top->setGraphic(this) ;
    return(this) ;
}

Top* TopGraphic::getTop(){ return(this->top) ; }

void TopGraphic::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    Parameters::setHoveredTop(this->getTop()) ;
    Window::main->refreshTops()->refreshArrets() ;
}

void TopGraphic::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    Parameters::setHoveredTop(NULL) ;
    Window::main->refreshTops()->refreshArrets() ;
}

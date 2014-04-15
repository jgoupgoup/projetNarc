#ifndef TOPGRAPHIC_H
#define TOPGRAPHIC_H
#include "../main.h"

class TopGraphic : public QGraphicsEllipseItem
{
public:

    // Propriétés statiques
    static float size ;

    static QColor defaultBackColor ;
    static QColor defaultBorderColor ;
    static float defaultBorderThickness ;

    static QColor startBackColor ;
    static QColor startBorderColor ;
    static float startBorderThickness ;

    static QColor endBackColor ;
    static QColor endBorderColor ;
    static float endBorderThickness ;

    static QColor hoverBackColor ;
    static QColor hoverBorderColor ;
    static float hoverBorderThickness ;

    // Méthodes statiques

    // Propriétés
    Top* top ;
    float x ;
    float y ;

    // Méthodes
    TopGraphic(float x, float y) ;
    TopGraphic* setTop(Top* top) ;
    Top* getTop() ;
    float getX() ;
    float getY() ;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) ;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) ;

};

#endif // TOPGRAPHIC_H

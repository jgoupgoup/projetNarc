#ifndef ARCGRAPHIC_H
#define ARCGRAPHIC_H
#include "../main.h"


class NarcGraphic : public QGraphicsLineItem
{
public:

    // Propriétés graphiques
    static float minThickness ;
    static float maxThickness ;
    static QColor disabledColor ;
    static QColor hoverColor ;

    // Propriétés
    float thickness ;
    Narc* arc ;

    // Méthodes
    NarcGraphic(float startX, float startY, float endX, float endY) ;
    NarcGraphic* setArc(Narc* arc) ;
    Narc* getArc() ;
    NarcGraphic* setThickness(float thickness) ;
    float getThickness() ;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) ;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) ;
};

#endif // ARCGRAPHIC_H

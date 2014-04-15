#include "../main.h"

SceneGraphic::SceneGraphic(QWidget* parent) : QGraphicsView(parent){

    //setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setDragMode(ScrollHandDrag);
}

void SceneGraphic::wheelEvent(QWheelEvent* event) {

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    double scaleFactor = 1.15 ;
    if(event->delta() > 0) {
        scale(scaleFactor, scaleFactor);
    } else {
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}

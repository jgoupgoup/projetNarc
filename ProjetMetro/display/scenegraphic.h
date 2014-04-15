#ifndef SCENE_H
#define SCENE_H

#include "../main.h"

class SceneGraphic : public QGraphicsView
{
    Q_OBJECT
public:
    SceneGraphic(QWidget* parent = NULL);
    void wheelEvent(QWheelEvent* event);
    void test();

signals:

public slots:

};

#endif // SCENE_H

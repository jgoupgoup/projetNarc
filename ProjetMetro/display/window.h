#ifndef WINDOW_H
#define WINDOW_H

#include "../main.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    static Window* main ;
    explicit Window(QWidget *parent = 0);
    Window* initScene() ;
    Window* initTops() ;
    Window* initArcs() ;

    Window* initForm() ;
    Window* initParcours() ;

    Window* refresh() ;

    Window* refreshScene() ;
    Window* refreshTops() ;
    Window* refreshArcs() ;

    Window* refreshForm() ;
    Window* refreshEnds() ;
    Window* refreshArrets() ;
    Window* refreshVoies() ;

    qint64 getLastRefresh() ;
    Window* updateLastRefresh() ;
    Window* pheromonesHaveChanged() ;

    ~Window();

public slots:
    void starttopChanged(int index);
    void endtopChanged(int index);
    void on_activeArcButton_clicked() ;
    void on_activeInverseArcButton_clicked() ;
    void on_startApplication_released() ;
    void refreshSlot() ;

private:
    Ui::Window *ui;
    QGraphicsScene* scene ;
    qint64 lastRefresh ;
};

#endif // WINDOW_H

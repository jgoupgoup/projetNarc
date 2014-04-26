#ifndef MAIN_H
#define MAIN_H

// Inclusions C++

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

// Inclusions Qt

#include <QThread>
#include <QMainWindow>
#include <QApplication>
#include <QtCore>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QScrollBar>
#include <QComboBox>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QMessageBox>

using namespace std;

// Inclusions projet

class Top ;
class Narc ;
class Ant ;
class Track ;
class TopGraphic ;
class NarcGraphic ;
class Thread ;

#include "beans/top.h"
#include "beans/narc.h"
#include "beans/ant.h"
#include "beans/track.h"

#include "display/window.h"
#include "display/topgraphic.h"
#include "display/arcgraphic.h"
#include "display/scenegraphic.h"


#include "intelligence/dataload.h"
#include "intelligence/parameters.h"
#include "intelligence/intelligence.h"
#include "intelligence/thread.h"

#endif // MAIN_H

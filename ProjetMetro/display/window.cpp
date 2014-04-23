#include "main.h"
#include "ui_window.h"

Window* Window::main = NULL;

Window::Window(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::Window) {
    Window::main = this ;

    this->ui->setupUi(this);

    this->initScene() ;
    this->initForm() ;
}

Window* Window::initScene(){
    this->scene = new QGraphicsScene(this) ;
    this->ui->graphic = new SceneGraphic(this) ;
    this->ui->graphic->resize(900,650);
    this->ui->graphic->setStyleSheet("border:none");
    this->ui->graphic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphic->setScene(this->scene);

    this->initTops();
    this->initArcs();
}

Window* Window::initTops(){

    float minX = 9999999 ; float maxX = -9999999 ;
    float minY = 9999999 ; float maxY = -9999999 ;
    float substractX = NULL; float divideX = NULL;
    float substractY = NULL; float divideY = NULL;

    vector<Top*> list = Top::getList() ;

    for(int i = 0 ; i < list.size() ; i++ ) {
        Top* top = list[i] ;
        if(top->getX() < minX) minX = top->getX() ;
        if(top->getX() > maxX) maxX = top->getX() ;
        if(top->getY() < minY) minY = top->getY() ;
        if(top->getY() > maxY) maxY = top->getY() ;
    }

    substractX = minX ; divideX = maxX - substractX ;
    substractY = minY ; divideY = maxY - substractY ;

    for(int i = 0 ; i < list.size() ; i++ ) {
        Top* top = list[i] ;
        float topX = ((top->getX() - substractX) / divideX) * (this->ui->graphic->width() - (2 * TopGraphic::size)) ;
        float topY = (-1) * ((top->getY() - substractY) / divideY) * (this->ui->graphic->height() - (2 * TopGraphic::size)) ;

        TopGraphic* topGraphic = new TopGraphic(topX,topY) ;
        topGraphic->setTop(top) ;
        this->scene->addItem(topGraphic);
    }

    Window::refreshTops() ;

    return(this) ;
}

Window* Window::initArcs(){

    vector<Narc*> arcList = Narc::getList() ;
    for(int i = 0 ; i < arcList.size() ; i++ ) {
        Narc* arc = arcList[i] ;
        NarcGraphic* arcGraphic = new NarcGraphic(
            arc->getStartTop()->getGraphic()->getX() + (TopGraphic::size/2),
            arc->getStartTop()->getGraphic()->getY() + (TopGraphic::size/2),
            arc->getEndTop()->getGraphic()->getX() + (TopGraphic::size/2),
            arc->getEndTop()->getGraphic()->getY() + (TopGraphic::size/2)
        ) ;
        arcGraphic->setArc(arc) ;
        this->scene->addItem(arcGraphic);
    }

    Window::refreshArcs() ;
    return(this) ;
}

Window* Window::initForm(){

    this->initParcours() ;

    return(this) ;
}

Window* Window::initParcours(){
    vector<Top*> list = Top::getList() ;

    this->ui->starttop->addItem("", -1);
    this->ui->endtop->addItem("", -1);

    for(int i = 0 ; i < list.size() ; i++ ) {
        Top* top = list[i] ;
        this->ui->starttop->addItem(top->getName().c_str(), top->getId());
        this->ui->endtop->addItem(top->getName().c_str(), top->getId());
    }

    connect(this->ui->starttop , SIGNAL(currentIndexChanged(int)),this,SLOT(starttopChanged(int)));
    connect(this->ui->endtop , SIGNAL(currentIndexChanged(int)),this,SLOT(endtopChanged(int)));

    return(this) ;
}

Window* Window::refresh(){
    this->refreshScene()->refreshForm() ;
}

Window* Window::refreshScene(){
    this->refreshTops()->refreshArcs() ;
}

Window* Window::refreshTops(){
    vector<Top*> list = Top::getList() ;

    for(int i = 0 ; i < list.size() ; i++ ) {
        Top* top = list[i] ;

        if(top == Parameters::getHoveredTop()){
            QBrush* brush = new QBrush(TopGraphic::hoverBackColor) ;
            QPen* pen = new QPen(TopGraphic::hoverBorderColor) ;
            pen->setWidth(TopGraphic::hoverBorderThickness);

            top->getGraphic()->setBrush(*brush) ;
            top->getGraphic()->setPen(*pen) ;
            top->getGraphic()->setZValue(14) ;
        }
        else if(top == Parameters::getStartTop()){
            QBrush* brush = new QBrush(TopGraphic::startBackColor) ;
            QPen* pen = new QPen(TopGraphic::startBorderColor) ;
            pen->setWidth(TopGraphic::startBorderThickness);

            top->getGraphic()->setBrush(*brush) ;
            top->getGraphic()->setPen(*pen) ;
            top->getGraphic()->setZValue(12) ;
        }
        else if(top == Parameters::getEndTop()){
            QBrush* brush = new QBrush(TopGraphic::endBackColor) ;
            QPen* pen = new QPen(TopGraphic::endBorderColor) ;
            pen->setWidth(TopGraphic::endBorderThickness);

            top->getGraphic()->setBrush(*brush) ;
            top->getGraphic()->setPen(*pen) ;
            top->getGraphic()->setZValue(11) ;
        }
        else{
            QBrush* brush = new QBrush(TopGraphic::defaultBackColor) ;
            QPen* pen = new QPen(TopGraphic::defaultBorderColor) ;
            pen->setWidth(TopGraphic::defaultBorderThickness);

            top->getGraphic()->setBrush(*brush) ;
            top->getGraphic()->setPen(*pen) ;
            top->getGraphic()->setZValue(10) ;
        }
    }

    return(this) ;
}


Window* Window::refreshArcs(){

    vector<Narc*> list = Narc::getList() ;

    /* Refresh thickness */
    float max = -9999999999 ;
    float min = 99999999999 ;
    for(int i = 0 ; i < Narc::list.size() ; i++ ){
        Narc* arc = Narc::list[i] ;
        if(arc->getPheromone() < min) min = arc->getPheromone() ;
        if(arc->getPheromone() > max ) max = arc->getPheromone() ;
    }

    for(int i = 0 ; i < Narc::list.size() ; i++ ){
        Narc* arc = Narc::list[i] ;
        arc->getGraphic()->setThickness((((arc->getPheromone() - min) / max)*4.9)+1.1) ;
        cout << (((arc->getPheromone() - min) / max)*4.9)+1.1 << endl ;
    }

    for(int i = 0 ; i < list.size() ; i++ ) {
        Narc* arc = list[i] ;

        if(arc == Parameters::getHoveredNarc()){
            QPen* pen = new QPen(NarcGraphic::hoverColor) ;
            pen->setCapStyle(Qt::RoundCap);
            pen->setWidth(arc->getGraphic()->getThickness());
            arc->getGraphic()->setPen(*pen);
            arc->getGraphic()->setZValue(17) ;
        }
        else if(arc->getAvailability() == false){
            QPen* pen = new QPen(NarcGraphic::disabledColor) ;
            pen->setCapStyle(Qt::RoundCap);
            pen->setWidth(NarcGraphic::minThickness);
            arc->getGraphic()->setPen(*pen);
            arc->getGraphic()->setZValue(16) ;
        }
        else{
            QPen* pen = new QPen(arc->getTrack()->getColor()) ;
            pen->setCapStyle(Qt::RoundCap);
            pen->setWidth(arc->getGraphic()->getThickness());
            arc->getGraphic()->setPen(*pen);
            arc->getGraphic()->setZValue(15) ;
        }
    }
    return(this) ;
}

Window* Window::refreshForm(){
    this->refreshEnds()->refreshArrets()->refreshVoies() ;
}

Window* Window::refreshEnds(){
    if(Parameters::isApplicationStarted()){
        this->ui->startApplication->setText("Arreter");
        this->ui->starttop->setEnabled(false);
        this->ui->endtop->setEnabled(false);
    }
    else{
        this->ui->startApplication->setText("Démmarer");
        this->ui->starttop->setEnabled(true);
        this->ui->endtop->setEnabled(true);
    }
    return(this) ;
}

Window* Window::refreshArrets(){

    Top* top = Parameters::getHoveredTop() ;
    if(top == NULL){
        this->ui->hoveredTop->setText("Aucun");
        this->ui->hoveredTopId->setText("");
    }
    else{
        QString topId = "#" ; topId += QString::number(top->getId()).toStdString().c_str() ;
        this->ui->hoveredTop->setText(top->getName().c_str());
        this->ui->hoveredTopId->setText(topId) ;
    }

    return(this) ;
}

Window* Window::refreshVoies(){
    Narc* arc = Parameters::getActiveNarc() ;

    if(arc == NULL) return(this) ;

    QString topA = "[A] " ; topA += arc->getStartTop()->getName().c_str() ;
    QString topB = "[B] " ; topB += arc->getEndTop()->getName().c_str() ;
    this->ui->activeArcTop1->setText(topA);
    this->ui->activeArcTop2->setText(topB);

    QString activeArcTitle = "A > B - #" ; activeArcTitle += QString::number(arc->getId()).toStdString().c_str() ;
    this->ui->activeArcId->setText(activeArcTitle) ;
    this->ui->activeArcExists->setText("Oui") ;
    this->ui->activeArcWeight->setText(QString::number(arc->getWeight())) ;
    this->ui->activeArcPheromones->setText(QString::number(arc->getPheromone())) ;
    if(arc->getAvailability() == true){
        this->ui->activeArcAvailable->setText("Oui") ;
        this->ui->activeArcButton->setText("Désactiver");
    }
    else{
        this->ui->activeArcAvailable->setText("Non") ;
        this->ui->activeArcButton->setText("Activer");
    }

    Narc* inverseArc = arc->getInverseArc() ;
    if(inverseArc != NULL){
        this->ui->activeInverseArcExists->setText("Oui") ;
        this->ui->activeInverseArcWeight->setText(QString::number(inverseArc->getWeight())) ;
        this->ui->activeInverseArcPheromones->setText(QString::number(inverseArc->getPheromone())) ;
        if(inverseArc->getAvailability() == true){
            QString activeInverseArcTitle = "B > A - #" ; activeInverseArcTitle += QString::number(inverseArc->getId()).toStdString().c_str() ;
            this->ui->activeInverseArcId->setText(activeInverseArcTitle) ;
            this->ui->activeInverseArcAvailable->setText("Oui") ;
            this->ui->activeInverseArcButton->setText("Désactiver");
        }
        else{
            QString activeInverseArcTitle = "B > A" ;
            this->ui->activeInverseArcId->setText(activeInverseArcTitle) ;
            this->ui->activeInverseArcAvailable->setText("Non") ;
            this->ui->activeInverseArcButton->setText("Activer");
        }
    }
    else{
        this->ui->activeInverseArcExists->setText("Non") ;
        this->ui->activeInverseArcWeight->setText("-") ;
        this->ui->activeInverseArcPheromones->setText("-") ;
        this->ui->activeInverseArcAvailable->setText("-") ;
    }

    return(this) ;
}


void Window::starttopChanged(int index){
    int id = this->ui->starttop->itemData(this->ui->starttop->currentIndex()).toInt() ;
    if(id < 0) Parameters::setStartTop(NULL) ;
    else Parameters::setStartTop(Top::getById(id)) ;
    Window::refreshTops() ;
}

void Window::endtopChanged(int index){
    int id = this->ui->endtop->itemData(this->ui->endtop->currentIndex()).toInt() ;
    if(id < 0) Parameters::setEndTop(NULL) ;
    else Parameters::setEndTop(Top::getById(id)) ;
    Window::refreshTops() ;
}

void Window::on_activeArcButton_clicked(){
    Narc* arc = Parameters::getActiveNarc() ;
    if(arc == NULL) return ;
    arc->setAvailability(!arc->getAvailability()) ;
    this->refreshScene() ;
    this->refreshForm() ;
}

void Window::on_activeInverseArcButton_clicked(){
    Narc* arc = Parameters::getActiveNarc() ;
    if(arc == NULL) return ;
    arc = arc->getInverseArc() ;
    if(arc == NULL) return ;
    arc->setAvailability(!arc->getAvailability()) ;
    this->refreshScene() ;
    this->refreshForm() ;
}

void Window::on_startApplication_clicked(){
    QMessageBox messageBox;
    if(!Parameters::isApplicationStarted()){
        if(Parameters::getStartTop() == NULL || Parameters::getEndTop() == NULL || Parameters::getStartTop() == Parameters::getEndTop()){
            messageBox.critical(0,"Error","Merci de définir un point de départ et un point d'arrivée différents");
            return ;
        }
        else
            messageBox.critical(0,"Error","C'est coool !");

        Ant::resetAll() ;

    }

    Parameters::switchApplicationStartState() ;

    if(Parameters::isApplicationStarted()){

        Intelligence::runTest() ;
    }

    Window::refreshForm() ;
}


Window::~Window()
{
    delete ui;
}

#include "../main.h"

Thread Intelligence::t ;

Intelligence::Intelligence()
{

}
void Intelligence::creationFourmis(int nbFourmis){
    for(int i=0; i<nbFourmis; i++){
        new Ant();
    }
}

void Intelligence::run(){
    new Ant() ;
    while(1){
        if(Parameters::isApplicationStarted()) {
            for(unsigned int j=0; j<Ant::list.size(); j++){
                Ant* ant = Ant::list[j];
                if(ant->getCurrentTop() != Parameters::getEndTop()){
                    Narc* narcChoosed = NULL;
                    narcChoosed = Narc::getBestNarcFrom(ant->getListAroundUnvisitedNarcs()) ;
                    ant->goThrough(narcChoosed) ;
                }
                else{
                    // On incréemnte les arcs visités
                    for(unsigned int i = 0 ; i < ant->getVisitedArcs().size() ; i++ ){
                        Narc* arc = ant->getVisitedArcs()[i] ;
                        arc->setPheromone(arc->getPheromone() + Parameters::getPheromonesIncrement()) ;
                    }
                    Window::main->refreshArcs() ;
                    ant->reset() ;
                }
            }
            // On décrémente tous les arcs
            for(unsigned int i = 0 ; i < Narc::list.size() ; i++ ){
                Narc* arc = Narc::list[i] ;
                arc->setPheromone(arc->getPheromone() * (1 - Parameters::getPheromonesDecrement())) ;
            }
        }
    }
}

void Intelligence::runTest(){
    while(1){
        Narc::getById(1)->setPheromone(0.1) ;
        Narc::getById(2)->setPheromone(0.2) ;
        Narc::getById(3)->setPheromone(0.3) ;
        Narc::getById(4)->setPheromone(0.4) ;
        Narc::getById(5)->setPheromone(0.5) ;
        Narc::getById(6)->setPheromone(0.6) ;
        Window::main->pheromonesHaveChanged() ;
    }
}


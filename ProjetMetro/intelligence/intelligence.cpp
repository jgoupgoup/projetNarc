#include "../main.h"

Intelligence::Intelligence()
{

}
void Intelligence::creationFourmis(int nbFourmis){
    for(int i=0; i<nbFourmis; i++){
        new Ant();
    }
}

static void Intelligence::run(){
    while(1){
        if(Parameters::isApplicationStarted()){
            for(int j=0; j<Ant::list.size(); j++){
                Ant* ant = Ant::list[j];
                if(ant->getCurrentTop()!=Parameters::getEndTop()){
                    //Elle regarde les arcs qu'elle a autour d'elle (non visité)
                    /*for(int k=0 ; k < Narc::listAroundUnvisitedNarcs() ; k++){

                        //Elle tire un narcs aléatoirement pondéramment

                        //Elle ajoute le narc tiré dans sa liste de narcs parcourus

                        //Elle va au top suivant
                    }*/
                }
                else{ //c'est qu'elle est rendue à la destination
                    //pour tous les nars de sa liste
                    //elle incremente les pheromones
                    //fin pour
                    //reset de la fourmi
                }
            }
        }
    }
}

static void Intelligence::runTest(){
    Narc::getById(1)->setPheromone(0.1) ;
    Narc::getById(2)->setPheromone(0.2) ;
    Narc::getById(3)->setPheromone(0.3) ;
    Narc::getById(4)->setPheromone(0.4) ;
    Narc::getById(5)->setPheromone(0.5) ;
    Narc::getById(6)->setPheromone(0.6) ;
    Window::refreshArcs() ;

}

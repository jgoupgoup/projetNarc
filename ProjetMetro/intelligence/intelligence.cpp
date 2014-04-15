#include "../main.h"

Intelligence::Intelligence()
{

}
void creationFourmis(int nbFourmis){
    for(int i=0; i<nbFourmis; i++){
        new Ant();
    }
}

static void run(){
    while(1){
        if(Parameters::isApplicationStarted()){
            for(int j=0; j<Ant::list.size(); j++){
                Ant* ant = Ant::list[j];
                if(ant->getCurrentTop()==Parameters::getEndTop()){
                    /*for(int k=0 ; k < Narc::listAroundUnvisitedNarcs() ; k++){

                    }*/
                }
            }
        }
    }
}

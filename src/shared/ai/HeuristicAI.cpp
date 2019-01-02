#include "HeuristicAI.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std::this_thread;
using namespace std;
using namespace ai;

HeuristicAI::HeuristicAI():AI(){

}
HeuristicAI::HeuristicAI(state::State* state):AI(){
  this->state=state;
}
HeuristicAI::~HeuristicAI(){

}

std::vector<std::string> HeuristicAI::run(std::vector<std::string>& list){
  std::vector<std::string> result;

  state::Room* room=(state::Room*) this->state->getGrid()->get(0,0);

  //Si la salle est vide on passe a la salle d'après
  if (room->getIsEmpty()){
    result.push_back("Next Room");
    result.push_back("None");
    return result;
  }


  Strategy* strategy = new Strategy(room->getTeamFullChara(),this->state);

  //Si l'équipe adverse a encore de la vie, on attaque...

  if (strategy->getLifeAdv()>0){
    result.push_back("Attack");}
  //out << "La commande " << list[r1] << " est effectuée" << endl;
  if (strategy->getLifeMin() == NULL){
    //Si un membre de notre équipe n'a pas de risque d'être tué bientôt
    //et que le personnage qui a le moins de défense et aussi celui qui a le moins de vie
    //on attaque ce dernier : sinon on attaque celui qui a le moins de vie
      if (strategy->getCibleDef() == strategy-> getCibleLife()){

        result.push_back(strategy->getCibleDef()->getName());}
      else {

        result.push_back(strategy->getCibleLife()->getName());}}
  else {

    result.push_back(strategy->getLifeMin()->getName());
    //Sinon on heal le personnage le plus mal en point dans notre équipe
    result[0]="Heal";}
    
  return result;
}

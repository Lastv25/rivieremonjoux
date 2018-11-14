#include "RandomAI.h"
#include <iostream>
#include <stdlib.h>



using namespace std;
using namespace ai;

RandomAI::RandomAI():AI(){

}
RandomAI::RandomAI(engine::Engine* engine,state::State* state):AI(){
  this->engine=engine;
  this->state=state;
}
RandomAI::~RandomAI(){

}


//std::string RandomAI::run(state::Team* team, state::Character* actChara, std::vector<std::string>& list){
std::vector<std::string> RandomAI::run(std::vector<std::string>& list){
  std::vector<std::string> result;
  int r1 = std::rand() % list.size();
  cout << "La commande " << list[r1] << " est effectuée" << endl;
  result.push_back(list[r1]);

  std::vector<std::string> intermediary;
  state::Room* room=(state::Room*) state->getGrid()->get(0,0);
  if (!room->getActive()->isMonster()){
    for (uint i=0; i< room->getHeroTeam()->getTeam().size();i++){
      intermediary.push_back( room->getHeroTeam()->getTeam()[i]->getName());
    }
  } else{
    for (uint i=0; i< room->getMonsterTeam()->getTeam().size();i++){
      intermediary.push_back( room->getMonsterTeam()->getTeam()[i]->getName());
    }
  }
  int r2 = std::rand() % intermediary.size();
  result.push_back(intermediary[r2]);
  return result;
}

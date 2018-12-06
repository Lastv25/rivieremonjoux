#include "RemoveFromTeam.h"
#include <iostream>

using namespace std;
using namespace engine;

//Constructor
RemoveFromTeam::RemoveFromTeam (){
  this->commandTypeId = Remove;
}
RemoveFromTeam::RemoveFromTeam (std::string charaPos){
  this->commandTypeId = Add;
  this->param=charaPos;
}
//Destructor
RemoveFromTeam::~RemoveFromTeam (){
}
//Operations
CommandTypeId RemoveFromTeam::getCommandTypeId (){
  return this->commandTypeId;
}
void RemoveFromTeam::execute (state::State* state){
  state::Tavern* t =(state::Tavern*) state->getGrid()->get(0,0);
  t->RemovefromTeamTavern(this->param);


}

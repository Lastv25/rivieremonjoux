#include "AddToTeam.h"
#include <iostream>
#include "../state/Tavern.h"
namespace state {
  class Tavern;
}
using namespace std;
using namespace engine;
using namespace state;
//Constructor
AddToTeam::AddToTeam (){
  this->commandTypeId = Add;
}
AddToTeam::AddToTeam (std::string charaName){
  this->commandTypeId = Add;
  this->param=charaName;
}

//Destructor
AddToTeam::~AddToTeam (){
}
//Operations
CommandTypeId AddToTeam::getCommandTypeId (){
  return this->commandTypeId;
}
void AddToTeam::execute (state::State* state){
  state::Tavern* t =(state::Tavern*) state->getGrid()->get(0,0);

  if (!t->isTeamFull()){
    t->AddtoTeamTavern(this->param);
  }
}
void AddToTeam::executeInv (state::State* state){
}

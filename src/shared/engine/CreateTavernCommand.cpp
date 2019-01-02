#include "CreateTavernCommand.h"
#include <iostream>

using namespace std;
using namespace engine;
#include "../state/Tavern.h"
#include "../state/Village.h"
namespace state {
  class Village;
  class Tavern;
}
using namespace state;
CreateTavernCommand::CreateTavernCommand ():Command(){
  this->commandTypeId = CreateTavern;
}
CreateTavernCommand::~CreateTavernCommand (){
}
CommandTypeId CreateTavernCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CreateTavernCommand::execute (state::State* state){

  state::Village* v =(state::Village*) state->getGrid()->get(0,0);
  cout << v->getTeam()->getTeam().size() <<endl;
  if(v->getTeam()->getTeam().size() == 0){
    state->getChar()->add(state->getGrid()->get(0,0),"Village");
    state->getGrid()->replaceElement(new state::Tavern(),"Tavern",0);

  } else {
    state->getChar()->add(state->getGrid()->get(0,0),"Village");
    state->getGrid()->replaceElement(new state::Tavern(v->getTeam(),3),"Tavern",0);
  }
}
void CreateTavernCommand::executeInv (state::State* state){
}

#include "CreateVillageCommand.h"
#include <iostream>
#include "../state/Village.h"
namespace state {
  class Village;
}
using namespace std;
using namespace engine;
using namespace state;

CreateVillageCommand::CreateVillageCommand ():Command(){
  this->commandTypeId = CreateVillage;
}
CreateVillageCommand::~CreateVillageCommand (){
}
CommandTypeId CreateVillageCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CreateVillageCommand::execute (state::State* state){
  state->getGrid()->add(new state::Village(),"Village");
}
void CreateVillageCommand::executeInv (state::State* state){
}

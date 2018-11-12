#include "CreateVillageCommand.h"
#include <iostream>

using namespace std;
using namespace engine;

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

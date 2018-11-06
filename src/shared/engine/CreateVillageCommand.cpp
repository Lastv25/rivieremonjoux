#include "CreateVillageCommand.h"
#include <iostream>

using namespace std;
using namespace engine;

CreateVillageCommand::CreateVillageCommand ():Command(){
}
CreateVillageCommand::~CreateVillageCommand (){
}
CommandTypeId CreateVillageCommand::getCommandTypeId (){
  return CreateVillage;
}
void CreateVillageCommand::execute (state::State* state){
  state->getGrid()->add(new state::Village(),"Village");
}

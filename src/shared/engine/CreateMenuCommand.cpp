#include "CreateMenuCommand.h"
#include <iostream>
#include "../state/Menu.h"
namespace state {
  class Menu;
}
using namespace std;
using namespace engine;
using namespace state;

CreateMenuCommand::CreateMenuCommand ():Command(){
  this->commandTypeId = CreateMenu;
}
CreateMenuCommand::~CreateMenuCommand (){
}
CommandTypeId CreateMenuCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CreateMenuCommand::execute (state::State* state){
  state->getGrid()->add(new state::Menu(),"Menu");
}
void CreateMenuCommand::executeInv (state::State* state){
}

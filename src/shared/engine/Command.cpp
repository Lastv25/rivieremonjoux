#include "Command.h"
#include <iostream>

using namespace std;
using namespace engine;

Command::Command (){
}
Command::~Command (){
}
CommandTypeId Command::getCommandTypeId (){
  return this->commandTypeId;
}
void Command::execute (state::State* state){
}

void Command::setCommandTypeId(CommandTypeId commandTypeId){
  this->commandTypeId = commandTypeId;
}

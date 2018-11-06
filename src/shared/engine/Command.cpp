#include "Command.h"
#include <iostream>

using namespace std;
using namespace engine;

Command::Command (){
}
Command::~Command (){
}
virtual CommandTypeId Command::getCommandTypeId (){
}
virtual void Command::execute (state::State* state){
}

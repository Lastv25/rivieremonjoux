#include "ChangeRoomCommand.h"
#include <iostream>
#include "../state/Dungeon.h"
namespace state {
  class Dungeon;
}

using namespace std;
using namespace engine;

//Constructor
ChangeRoomCommand::ChangeRoomCommand (){
  this->commandTypeId = ChangeRoom;
}
//Destructor
ChangeRoomCommand::~ChangeRoomCommand (){
}
//Operations
CommandTypeId ChangeRoomCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void ChangeRoomCommand::execute (state::State* state){
  cout <<"Here"<<endl;
  state::Dungeon* dungeon = (state::Dungeon*) state->getChar()->get(1,0);
  std::string newName = std::to_string(std::stoi(dungeon->getCurrentRoom())+1);
  //cout << "Change room name from "<<dungeon->getCurrentRoom() <<" to "<< newName<< endl;
  dungeon->setCurrentRoom(newName);
  state->getGrid()->replaceElement(dungeon,"Dungeon",0);
}

void ChangeRoomCommand::executeInv (state::State* state){
  state::Dungeon* dungeon = (state::Dungeon*) state->getChar()->get(1,0);
  std::string newName = std::to_string(std::stoi(dungeon->getCurrentRoom())-1);
  //cout << "Change room name from "<<dungeon->getCurrentRoom() <<" to "<< newName<< endl;
  dungeon->setCurrentRoom(newName);
  state->getGrid()->replaceElement(dungeon,"Dungeon",0);
}

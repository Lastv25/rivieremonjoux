#include "CreateRoomCommand.h"
#include <iostream>
#include <fstream>
#include "../state/Room.h"
#include "../state/Team.h"
namespace state {
  class Room;
  class Team;
}
using namespace std;
using namespace engine;
using namespace state;

CreateRoomCommand::CreateRoomCommand ():Command(){
  this->commandTypeId = CreateRoom;
}
CreateRoomCommand::CreateRoomCommand (std::string roomName):Command(){
  this->commandTypeId = CreateRoom;
  this->roomName = roomName;
}
CreateRoomCommand::~CreateRoomCommand (){
}
CommandTypeId CreateRoomCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CreateRoomCommand::execute (state::State* state){
  //cout << "Room Creation" <<endl;
  if (state->getDungeonExists()){

    state::Dungeon* d = (state::Dungeon*) state->getGrid()->get(0,0);
    //cout << "Room to create: "<<d->getCurrentRoom() <<endl;
    std::pair<bool,std::string> active = state->getOrder()[0];
    this->roomName=d->getCurrentRoom();
    if (d->getRoomList().size() == 0){
      cout << "The Dungeon is Cleared" << endl;
    } else {
      std::map<std::string,state::Team*> roomlist =d->getRoomList();
      bool intermediary_isMonster = std::get<0>(active);
      std::string intermediary_activeName = std::get<1>(active);
      int pos;
      // for (uint i =0;i<roomlist[this->roomName]->getTeam().size();i++){
      //   cout << roomlist[this->roomName]->getTeam()[i]->getName() <<endl;
      // }
      if (!intermediary_isMonster){
        pos = d->getHeroTeam()->getPos(intermediary_activeName);
      } else {
        pos = roomlist[this->roomName]->getPos(intermediary_activeName);
      }
      state->getChar()->add(state->getGrid()->get(0,0),"Dungeon");
      state->getGrid()->replaceElement(new state::Room(d->getHeroTeam(),roomlist[this->roomName],intermediary_isMonster,pos),"Room",0);
    }
  }
}
void CreateRoomCommand::executeInv (state::State* state){

}

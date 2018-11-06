#include "Dungeon.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Dungeon::Dungeon ():StaticElements(false){
}
Dungeon::Dungeon (std::vector<std::string> maps,Team* heroTeam):StaticElements(false){
  this->mapNames=maps;
}

//Destructor
Dungeon::~Dungeon (){
}

//Setters and Getters
const std::vector<std::string>& Dungeon::getMapNames() const{
  return this->mapNames;
}
void Dungeon::setMapNames(const std::vector<std::string>& mapNames){
  this->mapNames=mapNames;
}
const std::map<std::string,Team*>& Dungeon::getRoomList() const{
  this->RoomList;
}
void Dungeon::setRoomList(const std::map<std::string,Team*>& RoomList){
  this->RoomList=RoomList;
}
const std::string& Dungeon::getCurrentRoom() const{
  this->currentRoom;
}
void Dungeon::setCurrentRoom(const std::string& currentRoom){
  this->currentRoom=currentRoom;
}

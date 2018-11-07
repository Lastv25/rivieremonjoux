#include "Dungeon.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Dungeon::Dungeon ():StaticElements(false){
}
Dungeon::Dungeon (std::vector<std::string> maps,Team* heroTeam):StaticElements(false){
  this->mapNames=maps;
  this->heroTeam = heroTeam;
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
  return this->RoomList;
}
void Dungeon::setRoomList(const std::map<std::string,Team*>& RoomList){
  this->RoomList=RoomList;
}

Team* Dungeon::getHeroTeam (){
  return this->heroTeam;
}
void Dungeon::setHeroTeam (Team* newTeam){
  this->heroTeam=heroTeam;
}

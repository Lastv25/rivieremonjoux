#include <iostream>
#include <SFML/Graphics.hpp>
#include "DungeonDisplay.h"
#include <typeinfo>
#include "../../shared/state/Dungeon.h"
namespace state{
  class Dungeon;
}

using namespace state;
using namespace std;
using namespace render;
using namespace sf;

//Constructors
DungeonDisplay::DungeonDisplay (){
}
DungeonDisplay::DungeonDisplay (state::Element* e){
  state::Dungeon* d = (state::Dungeon*) e;
  this->dungeonList=d->getMapNames();
}
//Destructor
DungeonDisplay::~DungeonDisplay (){
}

//Getters and setters
std::vector<std::string> DungeonDisplay::getDungeonImages (){
  return this->listElementsinDungeon;
}


std::string DungeonDisplay::getDisplayText (){
  return this->displayText;
}
std::vector<std::string> DungeonDisplay::getDungeonList (){
  return this->dungeonList;
}
void DungeonDisplay::setDungeonList (std::vector<std::string> newList){
  this->dungeonList = newList;
}

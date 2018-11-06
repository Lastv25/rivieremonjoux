#include <iostream>
#include <SFML/Graphics.hpp>
#include "DungeonDisplay.h"
#include <typeinfo>


using namespace std;
using namespace render;
using namespace sf;

//Constructors
DungeonDisplay::DungeonDisplay (){
}
DungeonDisplay::DungeonDisplay (state::Element* e){
  state::Dungeon* d = (state::Dungeon*) e;
  std::vector<std::string> maps =d->getMapNames();
  std::string intermediary;
  for (uint i=0;i<maps.size();i++){
    intermediary=maps[i]+"\n";
  }
  this->dungeonList=intermediary;
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
std::string DungeonDisplay::getDungeonList (){
  return this->dungeonList;
}
void DungeonDisplay::setDungeonList (std::string newList){
  this->dungeonList = newList;
}

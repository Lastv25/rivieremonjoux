#include "Dungeon.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Dungeon::Dungeon ():StaticElements(false){
}
Dungeon::Dungeon (std::vector<std::string> maps):StaticElements(false){
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

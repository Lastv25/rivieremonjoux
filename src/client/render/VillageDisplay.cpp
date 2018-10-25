#include <iostream>
#include <SFML/Graphics.hpp>
#include "VillageDisplay.h"


using namespace std;
using namespace render;
using namespace sf;



//Constructor
VillageDisplay::VillageDisplay (){
}
//Destructor
VillageDisplay::~VillageDisplay (){
}
//Operations
std::vector<std::string> VillageDisplay::getVillageImages (){
  return this->listElementsinVillage;
}
void VillageDisplay::getFont (){
  if(!this->font.loadFromFile("res/dark-cristal/dc_s.ttf")){
    cout << "Font not found" << endl;
  }
}
std::string VillageDisplay::getDisplayText (){
  return this->displayText;
}

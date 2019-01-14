#include <iostream>
#include <SFML/Graphics.hpp>
#include "MenuDisplay.h"


using namespace std;
using namespace render;
using namespace sf;

//Constructor
MenuDisplay::MenuDisplay (){

}
MenuDisplay::MenuDisplay (state::Element* e){
}
//Destructor
MenuDisplay::~MenuDisplay (){
}

std::vector<std::string> MenuDisplay::getMenuImages (){
  return this->listElementsinMenu;
}
void MenuDisplay::getFont (){
  if(!this->font.loadFromFile("res/dark-cristal/dc_s.ttf")){
    cout << "Font not found" << endl;
  }
}
std::string MenuDisplay::getDisplayText (){
  return this->displayText;
}

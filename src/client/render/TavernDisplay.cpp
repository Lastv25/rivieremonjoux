#include <iostream>
#include <SFML/Graphics.hpp>
#include "TavernDisplay.h"


using namespace std;
using namespace render;
using namespace sf;

//Constructor
TavernDisplay::TavernDisplay (){
  this->listElementsinTavern.insert(this->listElementsinTavern.end(),this->listElementsinTavern1.begin(),this->listElementsinTavern1.end());
}
TavernDisplay::TavernDisplay (state::Element* e){
  this->listElementsinTavern.insert(this->listElementsinTavern.end(),this->listElementsinTavern1.begin(),this->listElementsinTavern1.end());
  state::Tavern* t = (state::Tavern*) e;
  if (t->getTeam()->getTeam().size() != 0){
    for (uint i=0;i<t->getTeam()->getTeam().size();i++){
      //cout <<"res/"+t->getTeam()->getTeam()[i]->getName()+"_Icon.png" << endl;
      this->team.push_back("res/"+t->getTeam()->getTeam()[i]->getName()+"_Icon.png");
    }
  }
}

//Destructor
TavernDisplay::~TavernDisplay (){
}

// Operations
std::string TavernDisplay::getDisplayText (){
  return this->displayText;
}
std::string TavernDisplay::getText (){
  return this->text;
}
std::vector<std::string> TavernDisplay::getTavernImages (){
  return this->listElementsinTavern;
}
std::vector<std::string> TavernDisplay::getTeam (){
  return this->team;
}

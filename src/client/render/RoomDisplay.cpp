#include <iostream>
#include <SFML/Graphics.hpp>
#include "RoomDisplay.h"


using namespace std;
using namespace render;
using namespace sf;

//Constructor
RoomDisplay::RoomDisplay (){

}
RoomDisplay::RoomDisplay (state::Element* e){
}
//Destructor
RoomDisplay::~RoomDisplay (){
}

std::string RoomDisplay::getDisplayText (){
  return this->displayText;
}

std::string RoomDisplay::getCharacter (){
  // std::vector<state::Character*> Heros = HeroTeam->getTeam();
  // std::vector<state::Character*> Monsters = MonsterTeam->getTeam();
  // for(uint i; i< Heros.size();i++){
  //   listCharacterIcon.push_back("res/"+Heros[i]->getName()+".png");
  //   listPosHero.push_back(i);
  // }
  // for(uint i; i< Monsters.size();i++){
  //   listCharacterIcon.push_back("res/"+Monsters[i]->getName()+".png");
  //   listPosMonst.push_back(i);
  // }
  listCharacterIcon.push_back("res/sorcerer.png");
  listPosHero.push_back(0);
  listCharacterIcon.push_back("res/sorcerer.png");
  listPosMonst.push_back(0);
  listElementsinRoom.push_back(listCharacterIcon[0]);
  listElementsinRoom.push_back(listCharacterIcon[1]);
}



std::string RoomDisplay::getCharacterStats (){
  state::Character* c =HeroTeam->getTeam()[0];
  this->characterStats = "Life: ";
  this->characterStats.append(std::to_string(c->getLife()));
  this->characterStats.append("\n Attack : ");
  this->characterStats.append(std::to_string(c->getATT()));
  this->characterStats.append("\n Defense : ");
  this->characterStats.append(std::to_string(c->getDEF()));
  this->characterStats.append("\n Speed : ");
  this->characterStats.append(std::to_string(c->getSPD()));
  this->characterStats.append("\n Crit : ");
  this->characterStats.append(std::to_string(c->getCrit()));
  return this->characterStats;
}

std::vector<std::string> RoomDisplay::getRoomImages (){
  return this->listElementsinRoom;
}

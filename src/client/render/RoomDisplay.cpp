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
  state::Room* room = (state::Room*) e;
  this->HeroTeam = room->getHeroTeam();
  this->MonsterTeam = room->getMonsterTeam();
  this->activeCharacter = room -> getActive();
}
//Destructor
RoomDisplay::~RoomDisplay (){
}

std::string RoomDisplay::getDisplayText (){
  return this->displayText;
}

std::string RoomDisplay::getCharacter (){

  std::vector<state::Character*> Heros = HeroTeam->getTeam();
  std::vector<state::Character*> Monsters = MonsterTeam->getTeam();
  std::vector<std::string> intermediaryList;
  //cout << Heros.size() << Monsters.size() << endl;
  uint tmp=0;

  for(uint i=0; i< Heros.size();i++){
    //cout << "res/"+Heros[i]->getName()+".png" << endl;
    intermediaryList.push_back("res/"+Heros[i]->getName()+".png");
    //cout << listCharacterIcon[i] << endl;
    this->listPosHero.push_back(i);
    this->listElementsinRoom.push_back(intermediaryList[i]);
    tmp += 1;
  }
  //cout <<"Monster Team size: "<< Monsters.size() <<endl;
  for(uint i=0; i< Monsters.size();i++){
    //cout << "res/"+Monsters[i]->getName()+".png" << endl;
    intermediaryList.push_back("res/"+Monsters[i]->getName()+".png");
    this->listPosMonst.push_back(i);
    this->listElementsinRoom.push_back(intermediaryList[tmp+i]);
  }
  // cout << this->listElementsinRoom.size()  << endl;
  // for(uint i=0; i< this->listElementsinRoom.size();i++){
  //   cout << this->listElementsinRoom[i] << endl;
  //
  // }

}



std::string RoomDisplay::getCharacterStats (){
  state::Character* c =this->activeCharacter;
  this->characterStats = c->getName();
  this->characterStats.append("\nLife =         ");
  this->characterStats.append(std::to_string(c->getLife()));
  this->characterStats.append("\nAttack =       ");
  this->characterStats.append(std::to_string(c->getATT()));
  this->characterStats.append("\nDefense =      ");
  this->characterStats.append(std::to_string(c->getDEF()));
  this->characterStats.append("\nSpeed =        ");
  this->characterStats.append(std::to_string(c->getSPD()));
  this->characterStats.append("\nCrit =         ");
  this->characterStats.append(std::to_string(c->getCrit()));
  return this->characterStats;
}

std::vector<std::string> RoomDisplay::getRoomImages (){
  return this->listElementsinRoom;
}

std::string RoomDisplay::getActiveName(){
  return this->activeCharacter->getName();
}

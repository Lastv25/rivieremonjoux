#include "Room.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Room::Room (Team* heroTeam, Team* monsterTeam, bool activeType, int activepos):Dungeon(){
  this->heroTeam=heroTeam;
  this->monsterTeam=monsterTeam;

  if (activeType){ // activeType ==1 when Monsters
    this->activeCharacter = monsterTeam->getTeam()[activepos];
  } else {
    this->activeCharacter = heroTeam->getTeam()[activepos];
  }
  this->isEmpty=false;
}
//Destructor
Room::~Room (){
}

//Setters and Getters
Team* Room::getHeroTeam (){
  return this->heroTeam;
}
void Room::setHeroTeam (Team* newTeam){
  this->heroTeam=heroTeam;
}
Team* Room::getMonsterTeam (){
  return this->monsterTeam;
}
void Room::setMonsterTeam (Team* newTeam){
  this->monsterTeam=newTeam;
}
void Room::setActive (Character* character){
  this->activeCharacter=character;
}
Character* Room::getActive (){
  return this->activeCharacter;
}
void Room::setIsEmpty (bool empty){
  this->isEmpty=empty;
}
bool Room::getIsEmpty (){
  return this->isEmpty;
}
Team* Room::getTeamFullChara (){
  std::vector<Character*> fTeam=heroTeam->getTeam();
  for (uint i=0;i<monsterTeam->getTeam().size();i++){
    fTeam.push_back(monsterTeam->getTeam()[i]);
  }
  // for (uint i=0;i<fTeam.size();i++){
  //   cout << fTeam[i]->getName();
  // }
  // cout << endl;
  this->teamFullChara=new Team(fTeam);
  return this->teamFullChara;
}
void Room::setTeamFullChara (Team* newTeam){
  this->teamFullChara=newTeam;
}

//Operations

bool Room::isBossRoom (){
  bool testBoss = true;
  for (uint i =0; i< this->monsterTeam->getTeam().size();i++){
    if (this->monsterTeam->getTeam()[i]->isBoss()){
      testBoss=false;
    }
  }
  return testBoss;
}

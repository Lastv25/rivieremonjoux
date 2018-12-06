#include "Team.h"
#include <vector>
#include <iostream>
using namespace state ;
using namespace std;

//Constructor
Team::Team (std::vector<Character*> listPerso){
  this->ListPerso = listPerso;
}
Team::Team(){
}
//Destructor
Team::~Team(){
}
//Setters and Getters
std::vector<Character*> Team::getTeam (){
  return this->ListPerso;
}
void Team::setTeam (std::vector<Character*> team){
  this->ListPerso = team;
}

//Methods
bool Team::isHeroTeam(){
  bool testHero = true;
  for (uint i =0; i< this->ListPerso.size();i++){
    cout << this->ListPerso[i]->getName()<<endl;
    if (this->ListPerso[i]->isMonster()){
      testHero=false;
    }
  }
  return testHero;
}
void Team::addToTeam (Character* character){
  uint tmp =0;
  for (uint i=0;i<this->ListPerso.size();i++){
    if (character->getName().find(this->ListPerso[i]->getName())!=std::string::npos){
      cout << "You already have this character in your team" <<endl;
    } else {tmp+=1;}
  }
  if (tmp ==this->ListPerso.size()){
    this->ListPerso.push_back(character);
  }
}

void Team::removeFromTeam (Character* character){
  std::vector<Character*> oldTeam = this->ListPerso;
  for (uint index=0; index<oldTeam.size(); index++ ){
    if (oldTeam[index]->getName() == character->getName()){
        oldTeam.erase(oldTeam.begin()+index);
    }
  }
  this->ListPerso =oldTeam;
}
int Team::getPos (std::string charaName){
  bool found =false;
  int intermediary;
  //cout << "Size Team:" << this->ListPerso.size() << " Character to find: "<<charaName<< endl;
  for (uint i=0; i< this->ListPerso.size();i++){
    std::string name =this->ListPerso[i]->getName();
    //cout <<"Perso in team: "<< this->ListPerso[i]->getName() <<" ";
    if (name.find(charaName)!= std::string::npos){
      intermediary = i;
      found=true;
    }
  }
  cout << endl;
  if (found){
    return intermediary;
  } else {
    return 1010;
  }
}

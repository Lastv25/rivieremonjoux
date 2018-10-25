
#include "Character.h"
#include <vector>
#include <iostream>
using namespace state ;
using namespace std;

// Constructeurs

Character::Character() : MobileElements(true){
}

Character::Character (int life, int att, int spd, int crit, int def,std::string name) : MobileElements(true){
    this->Life = life;
    this->LifeMAX = life;
    this->ATT = att;
    this->DEF = def;
    this->SPD = spd;
    this->Crit = crit;
    this->State = std::vector<int>  (1,0);
    this->name = name;
}

// Destructeur
Character::~Character (){
}

// Setters and Getters
int Character::getLife() {
  return this->Life;
}
int Character::getLifeMAX() {
  return this->LifeMAX;
}
int Character::getATT() {
  return this->ATT;
}
int Character::getDEF(){
  return this->DEF;
}
int Character::getSPD(){
  return this->SPD;
}
int Character::getCrit(){
  return this->Crit;
}
std::vector<int> Character::getState (){
  return this->State;
}
void Character::setLife(int i) {
  if (i<0){
    this->Life = 0;
  } else if (i>this->LifeMAX){
    this->Life = this->LifeMAX;
  } else {
    this->Life = i;
  }
}
void Character::setATT(int i) {
  this->ATT = i;
}
void Character::setDEF(int i){
  this->DEF=i;
}
void Character::setSPD(int i){
  this->SPD=i;
}
void Character::setCrit(int i){
  if (i>100){
    this->Crit=0;
  }else {
    this->Crit=i;
  }
}
std::string Character::getName(){
  return this->name;
}
void Character::setName(std::string newName){
  this->name=newName;
}
void Character::addState (int newState){
  this->State.push_back(newState);
}
void Character::clearState (int oldState){
  std::vector<int> oldStateList = this->State;
  for (uint index=0; index<oldStateList.size(); index++ ){
    if (oldStateList[index] == oldState){
        oldStateList.erase(oldStateList.begin()+index);
    }
  }
  this->State =oldStateList;
}
void Character::changeState (int newState){
  std::vector<int> oldStateList = this->State;
  bool teststate = false;
  bool statefound = false;
  if (newState == 3){ //Died
    this->State = std::vector<int>  (1,3);
  } else {
    if(newState == 0){ //Return to normal
      for (uint index=0; index<oldStateList.size(); index++ ){
        if (oldStateList[index] == newState){
            cout << "Character is already normal" << endl;
        } else {
            this->State = std::vector<int>  (1,0);
        }
      }
    } else if(newState == 1){
      for (uint index=0; index<oldStateList.size(); index++ ){
        if (oldStateList[index] == newState){
            teststate = true;
            cout << "Character is already poisoned" << endl;
        } else if(oldStateList[index] == 3){
            teststate = true;
            cout << "Character is dead, cannot be poisoned" << endl;
        } else if(oldStateList[index] == 2 ){
            statefound = true;
        } else {
            this->addState(1);
            this->clearState(0);
        }
      }
      if (teststate == false && statefound == true){this->addState(1);}
    } else if(newState == 2){
      for (uint index=0; index<oldStateList.size(); index++ ){
        if (oldStateList[index] == newState){
            teststate = true;
            cout << "Character is already stagered" << endl;
        } else if(oldStateList[index] == 3){
            teststate = true;
            cout << "Character is dead, cannot be stagered" << endl;
        } else if(oldStateList[index] == 1 ){
            statefound = true;
        } else {
            this->addState(2);
            this->clearState(0);
        }
      }
      if (teststate == false && statefound == true){this->addState(2);}
    } else {cout<<"The state "<<newState<<" is not defined"<<endl;}
  }
}
bool Character::isMonster (){
  return false;
}
bool Character::isBoss (){
  return isboss;
}

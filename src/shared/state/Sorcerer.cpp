#include "Sorcerer.h"
using namespace state ;
using namespace std;

//Constructor
Sorcerer::Sorcerer(int life, int att, int spd, int crit, int def,std::string name) : Monsters(life,att, spd, crit, def,name){
  this->skillList.push_back("Poison");
  this->skillpoints = 10;
}
//Destructor
Sorcerer::~Sorcerer(){
}
//Setter ang Getters
std::string Sorcerer::getName(){
  return this->name;
}
void Sorcerer::setName(std::string newName){
  this->name=newName;
}

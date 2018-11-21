#include "Mage.h"
using namespace state ;
using namespace std;

//Constructor
Mage::Mage(int life, int att, int spd, int crit, int def,std::string name) : Hero(life,att, spd, crit, def,name){
  this->skillList.push_back("Heal");
  this->skillpoints = 15;
}
//Destructor
Mage::~Mage(){
}
//Setter ang Getters
std::string Mage::getName(){
  return this->name;
}
void Mage::setName(std::string newName){
  this->name=newName;
}

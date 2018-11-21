#include "Tank.h"
using namespace state ;
using namespace std;

//Constructor
Tank::Tank(int life, int att, int spd, int crit, int def,std::string name) : Hero(life,att, spd, crit, def,name){
  this->skillList.push_back("HeavyAttack");
  this->skillpoints = 15;
}
//Destructor
Tank::~Tank(){
}
//Setter ang Getters
std::string Tank::getName(){
  return this->name;
}
void Tank::setName(std::string newName){
  this->name=newName;
}

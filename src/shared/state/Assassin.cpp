#include "Assassin.h"
using namespace state ;
using namespace std;

//Constructor
Assassin::Assassin(int life, int att, int spd, int crit, int def,std::string name) : Hero(life,att, spd, crit, def,name){
  this->skillList.push_back("Poison");
  this->skillpoints = 30;
}
//Destructor
Assassin::~Assassin(){
}
//Setter ang Getters
std::string Assassin::getName(){
  return this->name;
}
void Assassin::setName(std::string newName){
  this->name=newName;
}

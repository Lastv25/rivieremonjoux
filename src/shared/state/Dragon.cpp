#include "Dragon.h"
using namespace state ;
using namespace std;

//Constructor
Dragon::Dragon(int life, int att, int spd, int crit, int def,std::string name) : Monsters(life,att, spd, crit, def,name){
}
//Destructor
Dragon::~Dragon(){
}
//Setter ang Getters
std::string Dragon::getName(){
  return this->name;
}
void Dragon::setName(std::string newName){
  this->name=newName;
}

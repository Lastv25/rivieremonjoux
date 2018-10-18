#include "DarkKnight.h"
using namespace state ;
using namespace std;

//Constructor
DarkKnight::DarkKnight(int life, int att, int spd, int crit, int def,std::string name) : Monsters(life,att, spd, crit, def,name){
}
//Destructor
DarkKnight::~DarkKnight(){
}
//Setter ang Getters
std::string DarkKnight::getName(){
  return this->name;
}
void DarkKnight::setName(std::string newName){
  this->name=newName;
}

#include "Range.h"
using namespace state ;
using namespace std;

//Constructor
Range::Range(int life, int att, int spd, int crit, int def,std::string name) : Hero(life,att, spd, crit, def,name){
}
//Destructor
Range::~Range(){
}
//Setter ang Getters
std::string Range::getName(){
  return this->name;
}
void Range::setName(std::string newName){
  this->name=newName;
}

#include "Blob.h"
using namespace state ;
using namespace std;

//Constructor
Blob::Blob(int life, int att, int spd, int crit, int def,std::string name) : Monsters(life,att, spd, crit, def,name){
}
//Destructor
Blob::~Blob(){
}
//Setter ang Getters
std::string Blob::getName(){
  return this->name;
}
void Blob::setName(std::string newName){
  this->name=newName;
}

#include "Hero.h"
using namespace state ;
using namespace std;


// Constructeur
Hero::Hero () : Character() {
  this->ishero=true;
}

Hero::Hero (int life, int att, int spd, int crit, int def, std::string name) : Character(life,att, spd, crit, def,name){
  this->ishero=true;
}


// Destructeur
Hero::~Hero (){
}

bool Hero::isMonster (){
  return !this->ishero;
}

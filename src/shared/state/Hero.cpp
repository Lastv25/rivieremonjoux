#include "Hero.h"
using namespace state ;
using namespace std;


// Constructeur
Hero::Hero () : Character() {
}

Hero::Hero (int life, int att, int spd, int crit, int def, std::string name) : Character(life,att, spd, crit, def,name){
}


// Destructeur
Hero::~Hero (){
}

bool Hero::isMonster (){
  return !this->ishero;
}

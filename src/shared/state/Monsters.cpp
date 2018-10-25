#include "Monsters.h"
using namespace state ;
using namespace std;


// Constructeur
Monsters::Monsters () : Character() {
}

Monsters::Monsters (int life, int att, int spd, int crit, int def,std::string name) : Character(life,att, spd, crit, def,name){
}

// Destructeur
Monsters::~Monsters (){
}

bool Monsters::isMonster (){
  return !this->ishero;
}
bool Monsters::isBoss (){
  return this->isboss;
}

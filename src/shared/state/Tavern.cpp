#include <iostream>
#include "Tavern.h"
#include "Team.h"
using namespace std;
using namespace state;

Tavern::Tavern ():StaticElements(true){
  this->maxteam =3;
}

Tavern::Tavern (Team* team, uint maxTeam):StaticElements(true){
  this->team = team;
  this->maxteam =maxTeam;
}

Tavern::~Tavern(){
}

void Tavern::AddtoTeamTavern (Character* Character, Team* team){
  team->addToTeam(Character);
}

void Tavern::RemovefromTeamTavern (Character* Character, Team* team){
  team->removeFromTeam(Character);
}

Team* Tavern::getTeam (){
  return this->team;
}

bool Tavern::isTeamFull (){
  if(this->team->getTeam().size() == this->maxteam){
    cout << "The team is full" <<endl;
    return true;
  } else{ return false;}
}
void Tavern::getStat (Character* character){
  cout << "Att: "<<character->getATT() << endl;
  cout << "SPD: "<<character->getSPD() << endl;
  cout << "DEF: "<<character->getDEF() << endl;
  cout << "Crit: "<<character->getCrit() << endl;
}

void Tavern::getSkills (Character* character){
}

void Tavern::setOrder (Character* character, uint pos){
  Team* newTeam = new Team();
  uint i=0;
  for(std::vector<Character*>::iterator it=this->team->getTeam().begin();it!=this->team->getTeam().end();it++){
    if (i != pos){
      newTeam->addToTeam(this->team->getTeam()[i]);
    } else {
      newTeam->addToTeam(character);
    }
    i+=1;
  }
}

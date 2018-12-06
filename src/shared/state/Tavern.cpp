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

void Tavern::AddtoTeamTavern (std::string characterName){
  if(characterName.find("Tank")!=std::string::npos){
    this->team->addToTeam(new Tank(10,20,3,40,5,"Tank"));
  } else if(characterName.find("Mage")!=std::string::npos){
    this->team->addToTeam(new Mage(10,20,3,40,5,"Mage"));
  } else if(characterName.find("Assassin")!=std::string::npos){
    this->team->addToTeam(new Assassin(10,20,3,40,5,"Assassin"));
  } else if(characterName.find("Range")!=std::string::npos){
    this->team->addToTeam(new Range(10,20,3,40,5,"Range"));
  }
}

void Tavern::RemovefromTeamTavern (std::string charaPos){
  this->team->removeFromTeam(this->team->getTeam()[std::stoi(charaPos)]);
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

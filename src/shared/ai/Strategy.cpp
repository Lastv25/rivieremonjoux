#include "Strategy.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace ai;
using namespace state;

Strategy::Strategy(state::Team* team,state::State* state){
  int n=team->getTeam().size();
  bool ishero = team->isHeroTeam();
  std::vector<std::pair<bool,std::string>> order = state->getOrder();
  int minDef=5000;
  int minLife=5000;
  int minTeam=5000;
  int idef=-1;
  int ilife=-1;
  int iheal=-1;
  int lifeadv =0;
  int lifeMin = 0;
  int ifstadv=-1;
  int nrbAdv=0;
  setActChara(order[0].second);
  //On check le premier personnage à jouer dans l'équipe adverse
  for (int i=0;i<order.size();i++){
    if (order[i].first!=ishero){
      for(int j=0;j<n;j++){
        if (order[i].second==(team->getTeam()[j]->getName())){
          ifstadv=j;
        }
      }
    }
  }
  for (int i=0;i<n;i++){
    //Détermination du minimum de défense
    if (((team->getTeam()[i])->getDEF()<minDef) && team->getTeam()[i]->isMonster()==ishero){
      minDef = (team->getTeam()[i])->getDEF();
      idef = i;
    }
    //Détermination du minimum de vie
    if (((team->getTeam()[i])->getLife()<minLife) && team->getTeam()[i]->isMonster()==ishero){
      minLife = (team->getTeam()[i])->getLife();
      ilife = i;
    }
    if (team->getTeam()[i]->isMonster()==ishero){
      nbrAdv++;
    }
    //Détermination du minimum de vie dans l'équipe du joueur
    if ((team->getTeam()[i]->getLife()<(0.5*team->getTeam()[i]->getLifeMAX())) && ((team->getTeam()[i])->getLife()<minTeam)
    && (team->getTeam()[i]->isMonster()!=ishero)) {
      minTeam = team->getTeam()[i]->getLife();
      iheal = i;
    }
    //Somme des vies adverses
    lifeadv += team->getTeam()[i]->getLife();
  }
  // On ajouter finalement tous les personnages dans la stratégies qui est envoyée à l'IA
  setCibleDef(team->getTeam()[idef]);
  setCibleLife(team->getTeam()[ilife]);
  setLifeAdv(lifeadv);
  setFirst(team->getTeam()[ifstadv]);
  setNbrAdv(nbrAdv);
  //Si personne ne doit être soigné, on revoit un personnage NULL
  if (iheal !=-1){
    setLifeMin(team->getTeam()[iheal]);
  }
  else {
    setLifeMin(NULL);
  }
}

Strategy::~Strategy(){

}


void Strategy::setTeam (state::Team* team){
  this->team= team;
}

state::Team* Strategy::getTeam(){
  return this->team;
}

int Strategy::getNbrAdv(){
  return this->nbrAdv;
}

void Strategy::setNbrAdv (int nbrAdv){
  this->nbrAdv= nbrAdv;
}


void Strategy::setCibleDef (state::Character* cibleDef){
  this->cibleDef=cibleDef;
}

state::Character* Strategy::getCibleDef(){
  return this->cibleDef;
}

void Strategy::setCibleLife (state::Character* cibleLife){
  this->cibleLife=cibleLife;
}

state::Character* Strategy::getCibleLife(){
  return this->cibleLife;
}

void Strategy::setFirst (state::Character* firstAdv){
  this->firstAdv=firstAdv;
}

state::Character* Strategy::getFirst(){
  return this->firstAdv;
}

void Strategy::setLifeAdv (int lifeAdv){
  this->lifeAdv=lifeAdv;
}

int Strategy::getLifeAdv(){
  return this->lifeAdv;
}

void Strategy::setLifeMin (state::Character* lifeMin){
  this->lifeMin=lifeMin;
}

state::Character* Strategy::getLifeMin(){
  return this->lifeMin;
}

void Strategy::setActChara (std::string actChara){
  this->actChara=actChara;
}

std::string Strategy::getActChara(){
  return this->actChara;
}

#include "DeepAI.h"
#include <iostream>
#include <stdlib.h>
#include "Noeud.h"
#include <algorithm>

using namespace std;
using namespace ai;
using namespace state;

DeepAI::DeepAI():AI(){

}
DeepAI::DeepAI(state::State* state):AI(){
  this->state=state;
  this->arbre={};
  this->tasks = {};
  this->bestScore={};
}
DeepAI::~DeepAI(){

}

int DeepAI::calcScore(Strategy* strategy){
  int nbrAdv = strategy->getNbrAdv();
  int cibleDef = strategy->getCibleDef()->getDEF();
  int cibleLife = strategy->getCibleLife()->getLife();
  int lifeAdv = strategy->getLifeAdv();
  Character* firstAdv = strategy->getFirst();
  Character* actChara;
  //Character* actChara = state->getOrder()[0];
  std::string actCharaName = strategy->getActChara();
  std::vector<Character*> team = strategy->getTeam()->getTeam();
  for (uint k=0;k<team.size();k++){
    if (actCharaName==team[k]->getName()){
      actChara = team[k];
    }
  }
  int cntState = 0;
  for (uint i=0;i<team.size();i++){
    std::vector<int> charaState = team[i]->getState();
    for (uint j=0;j<charaState.size();j++){
      if(actChara->isMonster()==team[i]->isMonster()){
        cntState-=5*charaState[j];
      }
      else {
        cntState+=5*charaState[j];
      }
    }
  }
  int nbrTour =0;
  uint index =0 ;
  while((firstAdv!=team[index]) && (index<team.size())){
    index++;
    nbrTour++;
  }
  int score=500-nbrAdv*10+cntState-lifeAdv-cibleDef-cibleLife-5*nbrTour;
  return score;
}

int DeepAI::minmaxArbre(Noeud* noeud, int etageMax){
  int thisEtage = noeud->etage;
  int value;
  if (thisEtage%2==0){
    value = -10000;
    for (uint i=0;i<noeud->children.size();i++){
      value= std::max(value,minmaxArbre(noeud->children[i],etageMax-1));
    }
  }
  else if (thisEtage%2==1){
    value = 10000;
    for (uint i=0;i<noeud->children.size();i++){
      value= std::min(value,minmaxArbre(noeud->children[i],etageMax-1));
    }
  }
}

std::vector<std::string> DeepAI::run(std::vector<std::string>& list){
  state::Room* room=(state::Room*) this->state->getGrid()->get(0,0);
  Strategy* strategy = new Strategy(room->getTeamFullChara(),this->state);
  std::vector<std::string> result;
  std::string actChara = state->getActiveChara().second;
  Team* team = strategy->getTeam();
  std::vector<Noeud*> arbre ={};
  Strategy* strat = new Strategy(team,this->state);
  // Avec cette team, à chaque placement d'élément (création) on doit la modifier
  //et calculer son score pour place le doublet dans data de noeud
  std::pair<state::Team*,int> data = {team,calcScore(strat)};
  Noeud* tete = new Noeud(data);
  arbre.push_back(tete);
  Noeud* courant = tete;
  // while(courant->getEtage()!=-1){ // condition d'arret a trouver
  //   while(courant->getEtage() <etageMax && courant->getChildren().size() == this->tasks.size()){
  //     for (uint i=0;i<)
  //   }
  // }
  //Si l'équipe adverse a encore de la vie, on attaque...
  // while (strategy->getLifeAdv()>0){
  //   result.push_back("Attack");}
  // //out << "La commande " << list[r1] << " est effectuée" << endl;
  // state::Room* room=(state::Room*) state->getGrid()->get(0,0);
  // if (strategy->getLifeMin() == NULL){
  //   //Si un membre de notre équipe n'a pas de risque d'être tué bientôt
  //   //et que le personnage qui a le moins de défense et aussi celui qui a le moins de vie
  //   //on attaque ce dernier : sinon on attaque celui qui a le moins de vie
  //     if (strategy->getCibleDef() == strategy-> getCibleLife()){
  //       result.push_back(strategy->getCibleDef()->getName());}
  //     else {result.push_back(strategy->getCibleLife()->getName());}}
  // else {result.push_back(strategy->getLifeMin()->getName());
  //   //Sinon on heal le personnage le plus mal en point dans notre équipe
  //   result[0]="Heal";}
  return result;
}

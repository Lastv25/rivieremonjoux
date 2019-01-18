#include <algorithm>
#include <iostream>
#include "ElementTab.h"
#include "State.h"
using namespace state ;
using namespace std ;

State::State() {
  this->chars = new ElementTab();
  this->grid = new ElementTab();
}

State::~State(){

}

ElementTab* State::getGrid (){
  return this->grid;
}

ElementTab* State::getChar(){
  return this->chars;
}
std::pair<bool,std::string> State::getActiveChara (){
  return this->activeChara;
}
void State::setActiveChara (std::pair<bool,std::string> newActive){
  this->activeChara=newActive;
}
void State::setOrder (std::vector<std::pair<bool,std::string>> newOrder){
  this->activeOrder=newOrder;
}
std::vector<std::pair<bool,std::string>> State::getOrder (){
  return this->activeOrder;
}
void State::addToOrder (std::pair<bool,std::string> newPair){
  this->activeOrder.push_back(newPair);
}
void State::ReverseOrder (){
  if (!this->orderReversed){
    std::vector<std::pair<bool,std::string>> Order =this->activeOrder;
    std::reverse(Order.begin()+1,Order.end());
    setOrder(Order);
    this->orderReversed=true;
  }
}


bool State::getDungeonExists (){
  return this->dungeon_exists;
}
void State::setDungeonExists (bool exists){
  this->dungeon_exists=exists;
}
void State::stateChanged (){
  this->change=!this->change;
}
bool State::getChange (){
  return this->change;
}

int State::getPlayerConnected (){
  return this->playersConnected;
}
void State::setPlayerConnected (int newCount){
  this->playersConnected =newCount;
}

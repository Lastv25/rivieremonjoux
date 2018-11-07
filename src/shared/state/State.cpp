#include "ElementTab.h"
#include "State.h"
using namespace state ;
using namespace std ;

State::State() : Observable(){
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

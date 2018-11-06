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

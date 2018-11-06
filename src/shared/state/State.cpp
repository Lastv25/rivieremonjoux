#include "ElementTab.h"
#include "State.h"
using namespace state ;
using namespace std ;

State::State() : Observable(){
  this->chars = new ElementTab();
}

State::~State(){

}

ElementTab* State::getGrid (ElementTab* grid){
  return this->grid;
}

ElementTab* State::getChar(ElementTab* chars){
  return this->chars;
}

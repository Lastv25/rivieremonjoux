#include "ElementTab.h"
#include "State.h"
using namespace state ;
using namespace std ;

State::State() : Observable(){
  this->chars = new ElementTab();
}

State::~State(){

}

ElementTab* State::getGrid (){
  return this->grid;
}

ElementTab* State::getChar(){
  return this->chars;
}

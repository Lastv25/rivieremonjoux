#include "Element.h"
#include <iostream>

using namespace std;
using namespace state;


//Constructor
Element::Element (bool istat){
  staticElement = istat;
}

//Destructor
Element::~Element (){
}

// Setters and Getters
bool Element::getStaticElement() const{
  return this->staticElement;
}

void Element::setStaticElement(bool staticElement){
  this->staticElement = staticElement;
}

#include "StaticElements.h"
#include <iostream>
using namespace std;
using namespace state;

//Constructor
StaticElements::StaticElements(bool building) : Element(staticElement){
  this->building = building;
}

//Destructor
StaticElements::~StaticElements (){
}

bool StaticElements::isStatic(){
  return this->staticElement;
}

bool StaticElements::isBuilding(){
  return this->building;
}

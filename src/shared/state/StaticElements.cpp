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

// Setters and Getters
bool StaticElements::getBuilding() const{
  return this->building;
}
void StaticElements::setBuilding(bool building){
  this->building=building;
}
bool StaticElements::getStaticElement() const{
  return this->staticElement;
}
void StaticElements::setStaticElement(bool staticElement){
  this->staticElement=staticElement;
}

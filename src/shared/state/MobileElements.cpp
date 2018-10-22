#include "MobileElements.h"
#include <iostream>

using namespace std;
using namespace state;


//Constructor
MobileElements::MobileElements (bool iscara):  Element(staticElement){
  this->ischaracter = iscara;
}

//Destructor
MobileElements::~MobileElements(){
}

// Setters and Getters
bool MobileElements::getStaticElement() const{
  return this->staticElement;
}
void MobileElements::setStaticElement(bool staticElement){
  cout<<"The class mobile elements does not permit to change the static element variable"<<endl;
}
bool MobileElements::getIscharacter() const{
  return this->ischaracter;
}
void MobileElements::setIscharacter(bool ischaracter){
  this->ischaracter = ischaracter;
}


bool MobileElements::isCharacter(){
  return this->ischaracter;
}

bool MobileElements::isStatic(){
  return this->staticElement;
}

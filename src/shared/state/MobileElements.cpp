#include "MobileElements.h"


using namespace std;
using namespace state;


//Constructor
MobileElements::MobileElements (bool iscara):  Element(staticElement){
  this->ischaracter = iscara;
}

//Destructor
MobileElements::~MobileElements(){
}

bool MobileElements::isCharacter(){
  return this->ischaracter;
}

bool MobileElements::isStatic(){
  return this->staticElement;
}

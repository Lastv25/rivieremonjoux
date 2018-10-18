#include "MobileElements.h"
#include "CharacterIcon.h"
using namespace state ;
using namespace std ;

CharacterIcon::CharacterIcon():MobileElements(true){

}

CharacterIcon::~CharacterIcon(){

}

int CharacterIcon::getx(){
  return this->position_x ;
}

int CharacterIcon::gety(){
  return this->position_y ;
}

void CharacterIcon::setx(int x){
  this->position_x=x;
}

void CharacterIcon::sety(int y){
  this->position_y=y;
}

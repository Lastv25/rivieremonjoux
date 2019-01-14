#include "Menu.h"
using namespace state ;
using namespace std;

//Constructor
Menu::Menu() : StaticElements(true){
}
//Destructor
Menu::~Menu(){
}
//Setter ang Getters
Team* Menu::getTeam (){
  return this->team;
}
void Menu::setTeam (Team* team){
  this->team = team;
}
int Menu::getPlayerNumber (){
  return this->playerNumber;
}
void Menu::setPlayerNumber (int number){
  this->playerNumber = number;
}


#include "Village.h"
#include <vector>
#include <iostream>
using namespace std;
namespace state {

//Constructor
Village::Village ():StaticElements(true){
  this->team = new Team();
}
Village::Village (Tavern* tavern, Shop* shop, int money, Inventory* inventory, Team* team):StaticElements(true){
  this->tavern=tavern;
  this->shop=shop;
  this->Money=money;
  this->ListItems=inventory;
  this->team=team;
}

//Destructor
Village::~Village(){

}

void Village::mchurch(){
}
void Village::mtavern(){
}

void Village::mcarriage(Team* team){
  if (team->getTeam().size()<1){
    cout<< "Need at least one character in the Team before entering the dungeon"<< endl;
  }
}
Team* Village::getTeam (){
  return this->team;
}
void Village::setTeam (Team* team){
  this->team = team;
}

}

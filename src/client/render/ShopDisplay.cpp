#include <iostream>
#include <SFML/Graphics.hpp>
#include "ShopDisplay.h"


using namespace std;
using namespace render;
using namespace sf;



//Constructor
ShopDisplay::ShopDisplay (state::Inventory* inventory,state::Inventory* Shopinventory){
  this->inventory=inventory;
  this->shopinventory=Shopinventory;
}
//Destructor
ShopDisplay::~ShopDisplay (){
}
//Operations
std::vector<std::string> ShopDisplay::getShopImages (){
  return this->listElementsinShop;
}
void ShopDisplay::getFont (){
  if(!this->font.loadFromFile("res/dark-cristal/dc_s.ttf")){
    cout << "Font not found" << endl;
  }
}

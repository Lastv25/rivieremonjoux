#include "Shop.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Shop::Shop (Inventory* inventory, std::map<std::string,int> listItems,int money):StaticElements(true){
  this->inventory = inventory;
  this->ShopItems = listItems;
  this-> money = money;
}

//Destructor
Shop::~Shop (){
}

void Shop::AddtoInventory (std::string item, Inventory* inventory){
  inventory->addItem(item);
}
void Shop::RemovefromInventary (std::string item, Inventory* inventory){
  inventory->clearItem(item);
}

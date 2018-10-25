#include "Inventory.h"
#include <iostream>
#include "string.h"
using namespace std;
using namespace state;

//Constructors
Inventory::Inventory () {
}
Inventory::Inventory (uint length) {
  this-> inventorySize =length;
}
Inventory::Inventory (uint length,  std::map<std::string,int> inventory){
  this-> inventorySize =length;
  if (length < inventory.size()) {
    cout << "inventory too big for the defined size" << endl;
  } else  {
      this-> listItems = inventory;
  }
}
//Destructor
Inventory::~Inventory () {
}
//Getters and Setters
std::map<std::string,int> Inventory::getInventory (){
  return this->listItems;
}

int Inventory::getItemvalue (std::string name){
  for(std::map<std::string,int>::iterator it =this->listItems.begin(); it!=this->listItems.end();it++){
    if (it->first==name){
      return it->second;
    }
  }
}
void Inventory::addItem(std::string item){
  bool testitem=false;
  if(this->listItems.size()!=0 ){
    if(this->listItems.size()!=this->inventorySize){
      for (auto it : this->listItems){
        cout << it.first << endl;
        if (it.first==item){
          it.second +=1;

        } else {
          testitem=true;
        }
      }
    } else {
      cout << "inventory is already full" << endl;
    }
    if (testitem){
      this->listItems[item]=1;
    }
  } else {
    this->listItems[item]=1;
  }
}
void Inventory::clearItem(std::string name){
  for(std::map<std::string,int>::iterator it =this->listItems.begin(); it!=this->listItems.end();it++){
    if (it->first==name){
      this->listItems.erase(it);
    }
  }
}
void Inventory::removeItem (std::string name, int valuetoremove){
    for(std::map<std::string,int>::iterator it =this->listItems.begin(); it!=this->listItems.end();it++){
      if (it->first==name){
        if (it->second-valuetoremove<0){
          cout<<"You don't have enouth "<<it->first<< endl;
        } else {
          it->second-=valuetoremove;
        }
      }
    }
  }

#include "Item.h"
using namespace std;
using namespace state;

Item::Item (std::string name) : StaticElements(false){
  this-> name =name;
}

Item::~Item () {
}

std::string  Item::getName() {
  return this->name;
}

void Item::setName(std::string name){
  this->name = name;
}

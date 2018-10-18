#include "ElementTab.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
ElementTab::ElementTab (size_t height, size_t width){
  this->list = std::vector<Element*> (height*width);
  cout << list.size() << endl;
}

size_t ElementTab::add (Element* e){
  this->list.push_back(e);
  return this->list.size();
}

Element* ElementTab::get (int i, int j){
  return this->list[i];
}

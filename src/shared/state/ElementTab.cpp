#include "ElementTab.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
ElementTab::ElementTab (){
}

ElementTab::ElementTab (size_t height, size_t width){
  this->listElements = std::vector<Element*> (height*width);
  this->listClassNames = std::vector<std::string> (height*width);
}

size_t ElementTab::add (Element* e,std::string elementType){
  this->listElements.push_back(e);
  this->listClassNames.push_back(elementType);
  return this->listElements.size();
}

Element* ElementTab::get (int i, int j){
  return this->listElements[i];
}
std::string ElementTab::getElementType (int i){
  return this->listClassNames[i];
}

uint ElementTab::getSize(){
   return this->listElements.size();
 }

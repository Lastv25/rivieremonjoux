#include "ElementTab.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
ElementTab::ElementTab (): Observable(){
}

ElementTab::ElementTab (size_t height, size_t width): Observable(){
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
std::vector<Element*> ElementTab::getFullList (){
  return this->listElements;
}

std::string ElementTab::getElementType (int i){
  return this->listClassNames[i];
}
std::vector<std::string> ElementTab::getElementsTypes (){
  return this->listClassNames;
}

uint ElementTab::getSize(){
   return this->listElements.size();
 }

void ElementTab::replaceElement (Element* e,std::string type,int i){
  this->listElements.at(i)=e;
  this->listClassNames.at(i)=type;
}

void ElementTab::EraseLast(){

  this->listElements.pop_back();
  this->listClassNames.pop_back();
}

Element* ElementTab::Operator (int i, int j){

 }

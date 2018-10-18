#include "Element.h"
#include <iostream>

using namespace std;
using namespace state;


//Constructor
Element::Element (bool istat){
  staticElement = istat;
}

//Destructor
Element::~Element (){
}

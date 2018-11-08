#include "Event.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Event::Event(){
}
Event::Event(int i){
  this->eventType = i;
}
//Destructor
Event::~Event(){
}
//Operations
int Event::getEventTypeId(){
  return this->eventType;
}

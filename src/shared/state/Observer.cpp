#include "Observer.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Observer::Observer(){
}
//Destructor
Observer::~Observer(){
}
//Operations
void Observer::stateChanged(Event* e){
  if (e->getEventTypeId() == 1){
    cout << "State Event" << endl;
  } else {
    cout << "Tab Event" << endl;
    
  }
}

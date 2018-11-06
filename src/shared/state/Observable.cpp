#include "Observable.h"
#include <iostream>

using namespace std;
using namespace state;

//Constructor
Observable::Observable(){
}
//Destructor
Observable::~Observable(){
}

//Operations
void Observable::registerObserver (Observer* o){
  this->observers.push_back(o);
}
void Observable::unregisterObserver (Observer* o){
  for (uint i=0; i< this->observers.size();i++){
    if (this->observers[i] == o){
      this->observers.erase(this->observers.begin()+i);
    }
  }
}
void Observable::notifyObserver (Event* e){
}
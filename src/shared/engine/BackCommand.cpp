#include "BackCommand.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace engine;

BackCommand::BackCommand ():Command(){
  this->commandTypeId = Back;
}
BackCommand::~BackCommand (){
}
CommandTypeId BackCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void BackCommand::execute (state::State* state){

  if (state->getChar()->getSize() == 0){
    cout << "You cannot go back anymore" << endl;
  } else {
    state->getGrid()->replaceElement(state->getChar()->getFullList().back(),state->getChar()->getElementsTypes().back(),0);
    state->getChar()->EraseLast();
    state->Operator();
  }

}

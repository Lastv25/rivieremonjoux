#include "Engine.h"
#include <iostream>

using namespace std;
using namespace engine;

//Constructor
Engine::Engine (){
}
Engine::Engine (state::State* state){
  this->currentState=state;
}
//Destructor
Engine::~Engine (){
}
//Operations
state::State* Engine::getState (){
  return this->currentState;
}
void Engine::addPassiveCommands (){
}
void Engine::addCommand (int i ){
  if (i == 0){
    this->currentCommands[0]= new CreateDungeonCommand();
  } else if (i == 3){
    this->currentCommands[0]= new CreateVillageCommand();
  }

}
void Engine::update (){
  uint nbOfPossibleCommands = 7;
  for (uint i=0; i<nbOfPossibleCommands;i++){
    if(this->currentCommands.count(i) != 0){
      this->currentCommands[i]->execute(this->currentState);
      this->currentCommands.erase(i);
    }
  }
}

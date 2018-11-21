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
void Engine::setAdditionalParameters (std::string newParam){
  this->additionalParameters=newParam;
}
void Engine::setAdditionalParameters2 (std::string newParam){
  this->additionalParameters2=newParam;
}
state::State* Engine::getState (){
  return this->currentState;
}
void Engine::addPassiveCommands (){
}
void Engine::addCommand (int i ){
  if (i == 0){
    this->currentCommands.push_back( new CreateDungeonCommand());
  } else if (i == 3){
    this->currentCommands.push_back(new CreateVillageCommand());
  } else if (i == 8){
    this->currentCommands.push_back( new BackCommand());
  } else if (i == 1){
    this->currentCommands.push_back(new ChooseDungeonCommand(this->additionalParameters));
  } else if (i == 7){
    this->currentCommands.push_back(new CalculateActiveCommand());
  } else if (i == 2){
    this->currentCommands.push_back(new CreateRoomCommand());
  } else if (i == 4){
    if (this->additionalParameters.find("None")!=std::string::npos){
      this->currentCommands.push_back(new UseSkillCommand(this->additionalParameters2));
    } else {
      this->currentCommands.push_back(new UseSkillCommand(this->additionalParameters2,this->additionalParameters));
    }

  } else if (i == 6){
    this->currentCommands.push_back(new ChangeActiveCommand());
  } else if (i == 9){
    this->currentCommands.push_back(new ChangeRoomCommand());
  } else if (i == 10){
    this->currentCommands.push_back(new CreateTavernCommand());
  } else if (i == 11){
    this->currentCommands.push_back(new CheckCharaStateCommand());
  }


}
void Engine::update (){
  cout << "Update" << endl;

  bool changed = false;
  if (this->currentCommands.size()!=0){
    for (uint i=0; i<this->currentCommands.size();i++){
        this->currentCommands[i]->execute(this->currentState);
    }
    changed = true;
    this->currentCommands.clear();
  }
  if (changed){
    // this->currentState->Operator();
    // cout << "Engine ElementTab: "<< this->currentState->getGrid()->getSize() <<endl;
    // this->currentScene->stateChanged(this->currentState);
  }
}

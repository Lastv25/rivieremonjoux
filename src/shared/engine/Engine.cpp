#include "Engine.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include "jsoncpp.cpp"
#include "../engine/AddToTeam.h"
#include "../engine/BackCommand.h"
#include "../engine/CalculateActiveCommand.h"
#include "../engine/ChangeActiveCommand.h"
#include "../engine/ChangeRoomCommand.h"
#include "../engine/CheckCharaStateCommand.h"
#include "../engine/ChooseDungeonCommand.h"
#include "../engine/CreateRoomCommand.h"
#include "../engine/CreateTavernCommand.h"
#include "../engine/CreateDungeonCommand.h"
#include "../engine/CreateVillageCommand.h"
#include "../engine/RemoveFromTeam.h"
#include "../engine/UseSkillCommand.h"
namespace engine {
  class AddToTeam;
  class BackCommand;
  class CalculateActiveCommand;
  class ChangeActiveCommand;
  class ChangeRoomCommand;
  class CheckCharaStateCommand;
  class ChooseDungeonCommand;
  class CreateRoomCommand;
  class CreateTavernCommand;
  class CreateDungeonCommand;
  class CreateVillageCommand;
  class RemoveFromTeam;
  class UseSkillCommand;
}

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
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
void Engine::setRollback (bool rollback){
  this->rollback = rollback;
}
void Engine::addPassiveCommands (){
}
std::vector<std::tuple<int,std::string,std::string>> Engine::getCommandList (){
  return this->commandList;
}
void Engine::setCommandList (std::vector<std::tuple<int,std::string,std::string>> newCommandList){
  this->commandList=newCommandList;
}
void Engine::AddCommandTOList (int newCommand,std::string addParam1,std::string addParam2){
  std::tuple<int,std::string,std::string> command {newCommand,addParam1,addParam2};
  this->commandList.push_back(command);
}
std::tuple<int,std::string,std::string> Engine::RemoveLastFromCommandList (){
  std::tuple<int,std::string,std::string> output = this->commandList.back();
  this->commandList.pop_back();
  return output;
}
void Engine::Chrono(){
  if (this->startChrono){
    this->chrono +=1;
    if (this->chrono*3 >= 48){
      this->invCommands=true;
    }
  }
}
void Engine::addCommand (int i ){
  //cout <<"Command added: "<<i<<endl;
  if (!this->invCommands){
    if (!this->replay){
      AddCommandTOList(i,this->additionalParameters,this->additionalParameters2);
    }
  }
  if (getRecord()){
    RecordToJson (i);
  }
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
    if (this->rollback && !this->startChrono){
      this->startChrono=true;
    }
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
  } else if (i == 12){
    this->currentCommands.push_back(new AddToTeam(this->additionalParameters));
  } else if (i == 13){
    this->currentCommands.push_back(new RemoveFromTeam(this->additionalParameters));
  }


}
bool Engine::getRecord (){
  return this->record;
}
void Engine::setRecord (bool record){
  this->record=record;
}
void Engine::RecordToJson (int id){
  std::ofstream fout;
  fout.open("res/savedGames/recordedCommands.json",std::ofstream::out |std::ofstream::app);
  Json::Value event;
  event["command"]["ID"]=id;
  event["command"]["parameter1"]=this->additionalParameters;
  event["command"]["parameter2"]=this->additionalParameters2;
  //cout <<event<<endl;
  fout<<event<<";"<<std::endl;
  fout.close();
}
void Engine::JsonToEngine (){
  std::ifstream fin;
  fin.open("res/savedGames/recordedCommands.json",std::ifstream::binary);

  //get vector of commands in a string format
  std::string currentLine;
  std::string obj;
  std::vector<std::string> jsonCommands;
  while(std::getline(fin,currentLine)){
    if (currentLine.find(";")!=std::string::npos){
      jsonCommands.push_back(obj);
      obj.clear();
    } else {
      obj=obj+currentLine;
    }
  }
  fin.close();
  for (int i=0;i<4;i++){jsonCommands.erase(jsonCommands.begin());}


  //Each commad is send to the engine with it's parameters
  Json::Value root;
  Json::Reader reader;
  for (uint i=0;i<jsonCommands.size();i++){
    //cout<<jsonCommands[i]<<endl;
    reader.parse(jsonCommands[i],root,false);
    AddCommandTOList(root["command"]["ID"].asInt(),root["command"]["parameter1"].asString(),root["command"]["parameter2"].asString());
  }
  this->replay = true;
}
void Engine::update (){

  bool changed = false;
  if (!this->invCommands){
      if (this->currentCommands.size()!=0){
        for (uint i=0; i<this->currentCommands.size();i++){
              sleep_for(nanoseconds(100));
              this->currentCommands[i]->execute(this->currentState);
        }
      }
      changed = true;
      this->currentCommands.clear();
  } else {
    cout << "Rollback command "<<this->commandList.size() <<endl;
    std::tuple<int,std::string,std::string> command = RemoveLastFromCommandList();
    if (std::get<0>(command)==1){
      cout << "end of the rollback"<<endl;
    } else if (std::get<0>(command)==11){
      int i =0;
      while (i<3){
        this->currentCommands.clear();
        cout <<"command to execute: "<<std::get<0>(command)<<endl;
        sleep_for(nanoseconds(100));
        addCommand(std::get<0>(command));
        this->additionalParameters=std::get<1>(command);
        this->additionalParameters2=std::get<2>(command);
        this->currentCommands[0]->executeInv(this->currentState);
        command = RemoveLastFromCommandList();
        i+=1;
      }
    } else if (std::get<0>(command)==2){
      std::vector<std::tuple<int,std::string,std::string>> intermediaryCommandList;
      int i=0;
      while (i<4){
        command = RemoveLastFromCommandList();
        intermediaryCommandList.push_back(command);
        i+=1;
      }
      for (uint i=0; i<intermediaryCommandList.size();i++){
        this->currentCommands.clear();
        cout <<"command to execute: "<<std::get<0>(intermediaryCommandList[i])<<endl;
        sleep_for(nanoseconds(100));
        this->additionalParameters=std::get<1>(intermediaryCommandList[i]);
        this->additionalParameters2=std::get<2>(intermediaryCommandList[i]);
        addCommand(std::get<0>(intermediaryCommandList[i]));
        this->currentCommands[i]->execute(this->currentState);
      }
        this->currentCommands[0]->executeInv(this->currentState);
        command = RemoveLastFromCommandList();
    } else {
      this->currentCommands.clear();
      cout <<"command to execute: "<<std::get<0>(command)<<endl;
      sleep_for(nanoseconds(100));
      addCommand(std::get<0>(command));
      this->additionalParameters=std::get<1>(command);
      this->additionalParameters2=std::get<2>(command);
      this->currentCommands[0]->executeInv(this->currentState);
      command = RemoveLastFromCommandList();
    }
  }
  if (changed){
    this->currentState->stateChanged();
    // cout << "Engine ElementTab: "<< this->currentState->getGrid()->getSize() <<endl;
    // this->currentScene->stateChanged(this->currentState);
  }
}

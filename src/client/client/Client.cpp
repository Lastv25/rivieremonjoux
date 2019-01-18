#include "Client.h"
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <thread>
#include <chrono>



using namespace std;
using namespace client;
using namespace std::chrono;
using namespace std::this_thread;
using namespace engine;
using namespace ai;


Client::Client (){
}
Client::Client (engine::Engine* engine, ai::HeuristicAI* ai){
  this->engine=engine;
  this->ai = ai;
}
Client::Client (engine::Engine* engine, ai::HeuristicAI* ai,bool replay){
  this->engine=engine;
  this->ai = ai;
  this->replay = replay;
}
Client::~Client (){
}

//function for the engine update thread
void Client::UpdateEngine() {

  while (1){
    sleep_for(seconds(1));
    this->engine->update();

  }
}

void Client::getCommandsAI_h_Id (std::string action){
  //get commands ID
  std::vector<int> commands;
  if(action.find("Attack")!=std::string::npos){
    commands.push_back(4);
    commands.push_back(6);
    commands.push_back(11);
  } else if(action.find("HeavyAttack")!=std::string::npos){
    commands.push_back(4);
    commands.push_back(6);
    commands.push_back(11);
  } else if(action.find("Poison")!=std::string::npos){
    commands.push_back(4);
    commands.push_back(6);
    commands.push_back(11);
  } else if(action.find("Heal")!=std::string::npos){
    commands.push_back(4);
    commands.push_back(6);
    commands.push_back(11);
  }else if(action.find("Next Turn")!=std::string::npos){
    commands.push_back(6);
    commands.push_back(11);
  }else if(action.find("Next Room")!=std::string::npos){
    commands.push_back(8);
    commands.push_back(9);
    commands.push_back(7);
    commands.push_back(2);
  }
  //send commands to engine
  for (uint i=0; i<commands.size() ; i++){
        this->engine->addCommand(commands[i]);
  }
  this->engine->Chrono();
}

//function for ia thread if ia is heuristic
void Client::CommandsAI_h() {

  //Command list
  std::string c1 = "Attack";
  std::string c3 = "Poison";
  std::string c2 = "Next Turn";
  std::string c4 = "Heavy Attack";
  std::vector<std::string> l={c1,c2,c3,c4} ;

  std::vector<std::string> actionia;
  while(1){
    sleep_for(std::chrono::seconds(3));
    if (this->ai->getStateType().find("Room")!=std::string::npos){
      //cout <<"Room found by client"<<endl;
      this->newAICommand=true;
      std::vector<std::string> actionia = this->ai->run(l);
      std::string attackName = actionia[0];
      std::string target = actionia[1];
      cout << attackName << target <<endl;
      if (!this->replay){
        this->engine->setAdditionalParameters(target);
        this->engine->setAdditionalParameters2(attackName);
        getCommandsAI_h_Id(attackName);
        this->newAICommand=false;
      }
    }
  }
}

void Client::run (){
  //run Engine and IA threads

  this->t1= std::thread ([this] {UpdateEngine();});
  this->t2=std::thread ([this] {CommandsAI_h();});

}
void Client::end (){
  //Close the Threads
  this->t1.join();
  this->t2.join();
}

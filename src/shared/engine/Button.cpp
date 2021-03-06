#include "Button.h"
#include <iostream>


using namespace std;
using namespace engine;

//Constructor
Button::Button (Engine* engine){
  this->engine=engine;
}
Button::Button (){
}
//Destructor
Button::~Button (){
}
//Setters and Getters
std::string Button::getAdditionalParam (){
  return this->additionalParameters;
}
void Button::setAdditionalParam (std::string newParam){
  this->additionalParameters=newParam;
  this->engine->setAdditionalParameters(newParam);
}
void Button::setSkillName (std::string skillName){
  this->skillName=skillName;
  this->engine->setAdditionalParameters2(skillName);
}
std::string Button::getSkillName (){
  return this->skillName;
}
//Operations
void Button::setCommand(std::string button){
  if (button.find("None")==std::string::npos){
    this->button=button;
  }
}
std::vector<int> Button::getCommands (){
  if(this->button.find("Dungeon")!=std::string::npos){
    this->commands.push_back(0);
  } else if(this->button.find("Village")!=std::string::npos){
    this->commands.push_back(3);
  } else if(this->button.find("Tavern")!=std::string::npos){
    this->commands.push_back(10);
  } else if(this->button.find("Back")!=std::string::npos){
    this->commands.push_back(8);
  } else if(this->button.find("Attack")!=std::string::npos){
    this->commands.push_back(4);
    this->commands.push_back(6);
    this->commands.push_back(11);
  } else if(this->button.find("HeavyAttack")!=std::string::npos){
    this->commands.push_back(4);
    this->commands.push_back(6);
    this->commands.push_back(11);
  } else if(this->button.find("Poison")!=std::string::npos){
    this->commands.push_back(4);
    this->commands.push_back(6);
    this->commands.push_back(11);
  } else if(this->button.find("Heal")!=std::string::npos){
    this->commands.push_back(4);
    this->commands.push_back(6);
    this->commands.push_back(11);
  }else if(this->button.find("Next Turn")!=std::string::npos){
    this->commands.push_back(6);
    this->commands.push_back(11);
  }else if(this->button.find("Next Room")!=std::string::npos){
    this->commands.push_back(8);
    this->commands.push_back(9);
    this->commands.push_back(7);
    this->commands.push_back(2);
  }else if(this->button.find("Add")!=std::string::npos){
    this->commands.push_back(12);
  }else if(this->button.find("Remove")!=std::string::npos){
    this->commands.push_back(13);
  }else if(this->button.find("1 Player")!=std::string::npos){
    this->commands.push_back(3);
  }else if(this->button.find("2 Players")!=std::string::npos){
    this->commands.push_back(15);
    this->commands.push_back(16);
  }else {
    this->commands.push_back(1);
    this->commands.push_back(7);
    this->commands.push_back(2);
  }
  return commands;
}

void Button::sendToEngine (){
  if (this->commands.size()==0){
    getCommands();
  }
  //cout << "Nbr of commands: "<<this->commands.size()  << endl;
  for (uint i=0; i<this->commands.size() ; i++){
        this->engine->addCommand(this->commands[i]);
  }
  this->commands.clear();
  this->engine->Chrono();
  this->engine->update();
  setCommand("None");
}

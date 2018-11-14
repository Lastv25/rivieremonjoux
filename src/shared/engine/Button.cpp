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
  } else if(this->button.find("Back")!=std::string::npos){
    this->commands.push_back(8);
  } else if(this->button.find("Attack")!=std::string::npos){
    this->commands.push_back(4);
    this->commands.push_back(6);
  }else if(this->button.find("Next Turn")!=std::string::npos){
    this->commands.push_back(6);
  }else if(this->button.find("Next Room")!=std::string::npos){
    this->commands.push_back(8);
    this->commands.push_back(9);
    this->commands.push_back(7);
    this->commands.push_back(2);
  }else {
    this->commands.push_back(1);
    this->commands.push_back(7);
    this->commands.push_back(2);
  }
  return commands;
}

void Button::sendToEngine (){
  getCommands();
  //cout << "Nbr of commands: "<<this->commands.size()  << endl;
  for (uint i=0; i<this->commands.size() ; i++){
        this->engine->addCommand(this->commands[i]);
  }
  this->commands.clear();
  this->engine->update();
  setCommand("None");
}

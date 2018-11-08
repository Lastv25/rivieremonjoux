#include "Button.h"
#include <iostream>


using namespace std;
using namespace engine;

//Constructor
Button::Button (std::string button){
  this->button=button;
}
Button::Button (){
}
//Destructor
Button::~Button (){
}
//Operations
void Button::setCommand(std::string button){
  if (button.find("None")==std::string::npos){
    this->button=button;
  }
}
std::vector<int> Button::getCommands (){
  std::vector<int> commands;
  if(this->button.find("Dungeon")!=std::string::npos){
    commands.push_back(0);
  } else if(this->button.find("Village")!=std::string::npos){
    commands.push_back(3);
  }
  return commands;
}

#include "AI.h"
#include <iostream>
#include <stdlib.h>



using namespace std;
using namespace ai;


AI::AI(){

}

AI::~AI(){

}

//std::string AI::run(state::Team* team, state::Character* actChara, std::vector<std::string>& list){
std::vector<std::string> AI::run(std::vector<std::string>& list){
}
const std::string& AI::getStateType() const{
  return this->stateType;
}
void AI::setStateType(const std::string& stateType){
  this->stateType=stateType;
}

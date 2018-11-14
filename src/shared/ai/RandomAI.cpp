#include "RandomAI.h"
#include <iostream>
#include <stdlib.h>



using namespace std;
using namespace ai;
using namespace state;

RandomAI::RandomAI(){

}

RandomAI::~RandomAI(){

}


//std::string RandomAI::run(state::Team* team, state::Character* actChara, std::vector<std::string>& list){
std::string RandomAI::run(std::vector<std::string>& list){
  int r = std::rand() % list.size();
  cout << "La commande " << list[r] << " a été effectuée" << endl;

  return list[r];
}

#include "PotionVie.h"
using namespace std;
using namespace state;

PotionVie::PotionVie (int i,std::string name) : Item(name){
  this-> RegenVie =i;
}

PotionVie::~PotionVie () {
}

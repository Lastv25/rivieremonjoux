#include "PotionSoin.h"
using namespace std;
using namespace state;

PotionSoin::PotionSoin (int i,std::string name) : Item(name){
  this-> Regen =i;
}

PotionSoin::~PotionSoin () {
}

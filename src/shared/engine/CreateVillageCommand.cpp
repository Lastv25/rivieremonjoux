#include "CreateVillageCommand.h"
#include <iostream>
#include "../state/Village.h"
#include "../state/Team.h"
#include "../state/Tank.h"
#include "../state/Range.h"
#include "../state/Assassin.h"
namespace state {
  class Village;
  class Team;
  class Tank;
  class Range;
  class Assassin;
}
using namespace std;
using namespace engine;
using namespace state;

CreateVillageCommand::CreateVillageCommand (bool team):Command(){
  this->commandTypeId = CreateVillage;
  this->team=team;
}
CreateVillageCommand::~CreateVillageCommand (){
}
CommandTypeId CreateVillageCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CreateVillageCommand::execute (state::State* state){
  if (this->team){
    Team* team = new Team();
    Village* v= new state::Village();
    Tank* tank = new Tank(10,20,3,40,5,"Tank");
    Range* range = new Range(10,20,3,40,5,"Range");
    Assassin* assassin = new Assassin(10,20,3,40,5,"Assassin");
    team->addToTeam(tank);
    team->addToTeam(range);
    team->addToTeam(assassin);
    v->setTeam(team);
    state->getChar()->add(state->getGrid()->get(0,0),"Menu");
    state->getGrid()->replaceElement(v,"Village",0);
  } else {
    state->getGrid()->add(new state::Village(),"Village");
  }
}
void CreateVillageCommand::executeInv (state::State* state){
}

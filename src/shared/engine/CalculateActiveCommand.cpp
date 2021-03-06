#include "CalculateActiveCommand.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include "../state/Dungeon.h"
#include "../state/Team.h"
namespace state {
  class Dungeon;
  class Team;
}

using namespace std;
using namespace engine;
using namespace state;

//Constructor
CalculateActiveCommand::CalculateActiveCommand ():Command(){
  this->commandTypeId = CalculateActive;
}

//Destructor
CalculateActiveCommand::~CalculateActiveCommand (){
}
CommandTypeId CalculateActiveCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CalculateActiveCommand::execute (state::State* states){
  if (states->getDungeonExists()){
    state::Dungeon* dungeon = (state::Dungeon*) states->getGrid()->get(0,0);
    std::map<std::string,state::Team*> RoomList;
    state::Team* heroTeam = dungeon->getHeroTeam();
    RoomList=dungeon->getRoomList();
    state::Team* monsterTeam = RoomList[dungeon->getCurrentRoom()];

    std::vector<uint> pos;
    std::vector<int> spd;
    std::vector<std::string> names;
    std::vector<bool> isMonster;
    std::vector<std::pair<bool,std::string>> order;

    for (uint i=0 ; i< heroTeam->getTeam().size();i++){
      pos.push_back(i);
      spd.push_back(heroTeam->getTeam().at(i)->getSPD());
      names.push_back(heroTeam->getTeam().at(i)->getName());
      isMonster.push_back(0);
    }
    for (uint i=0 ; i< monsterTeam->getTeam().size();i++){
      pos.push_back(i);
      spd.push_back(monsterTeam->getTeam().at(i)->getSPD());
      names.push_back(monsterTeam->getTeam().at(i)->getName());
      isMonster.push_back(1);
    }
    // for (uint i=0;i<names.size();i++){
    //   cout << names[i]<< ":"<<spd[i]<<" ";
    // }
    // cout << endl;

    uint intermediary_pos = 0;
    int intermediary_spd = spd[intermediary_pos];
    while (pos.size() != 0){
      for (uint i=0 ; i< pos.size();i++){

        if (intermediary_spd <= spd[i]){
          intermediary_spd = spd[i];
          intermediary_pos = i;
        }
      }

      order.push_back(std::pair<bool,std::string>(isMonster[intermediary_pos],names[intermediary_pos]));
      names.erase(names.begin()+intermediary_pos);
      pos.erase(pos.begin()+intermediary_pos);
      spd.erase(spd.begin()+intermediary_pos);
      isMonster.erase(isMonster.begin()+intermediary_pos);
    }
    states->setOrder(order);

    cout << "Order of the turns" << endl;
    for (uint i=0;i<order.size();i++){
      cout << i;
      cout << ":";
      cout << std::get<1>(order[i]);
      cout << ", ";
    }
    cout << endl;
  }
}
void CalculateActiveCommand::executeInv (state::State* state){
  execute(state);
}

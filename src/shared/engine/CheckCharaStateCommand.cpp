#include "CheckCharaStateCommand.h"
#include <iostream>
#include "../state/Room.h"
namespace state {
  class Room;
}
using namespace std;
using namespace engine;
using namespace state;
//Constructor
CheckCharaStateCommand::CheckCharaStateCommand (){
  this->commandTypeId = CheckCharaState;
}
//Destructor
CheckCharaStateCommand::~CheckCharaStateCommand (){
}
//Operations
CommandTypeId CheckCharaStateCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void CheckCharaStateCommand::execute (state::State* state){
  state::Room* room = (state::Room*) state->getGrid()->get(0,0);
  state::Character* active = room ->getActive();
  cout << "Active Turn Effect: "<<active->getTurnEffect()<<endl;
  if (active->getTurnEffect()!=0){
    active->setTurnEffect(active->getTurnEffect()-1);
    for (uint i=0;i<active->getState().size();i++){
      if (active->getState()[i]==1){
        active->setLife(active->getLife()-3);
        cout << active->getName() << " suffered " << 3 << " damages due to poisoning"<<endl;
      }
    }

  }
}

void CheckCharaStateCommand::executeInv (state::State* state){
  state::Room* room = (state::Room*) state->getGrid()->get(0,0);
  state::Character* active = room ->getActive();
  cout << "Active Turn Effect: "<<active->getTurnEffect()<<endl;
  if (active->getTurnEffect()!=0){
    active->setTurnEffect(active->getTurnEffect()+1);
    for (uint i=0;i<active->getState().size();i++){
      if (active->getState()[i]==1){
        active->setLife(active->getLife()+3);
        cout << active->getName() << " regained " << 3 << " life points due to rollback poisoning"<<endl;
      }
    }

  }


}

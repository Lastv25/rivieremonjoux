#include "UseSkillCommand.h"
#include <iostream>

using namespace std;
using namespace engine;

//Constructor
UseSkillCommand::UseSkillCommand (){
  this->commandTypeId = UseSkill;
}
UseSkillCommand::UseSkillCommand (std::string skillName){
  this->commandTypeId = UseSkill;
  this->skillName = skillName;
  this->specifiedReciever = false;
}
UseSkillCommand::UseSkillCommand (std::string skillName,std::string receiver){
  this->commandTypeId = UseSkill;
  this->skillName = skillName;
  this->receiverName = receiver;
  this->specifiedReciever = true;
}
//Destructor
UseSkillCommand::~UseSkillCommand (){
}
//Operations
CommandTypeId UseSkillCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void UseSkillCommand::execute (state::State* state){
  state::Room* room = (state::Room*) state->getGrid()->get(0,0);
  state::Character* attacker = room ->getActive();
  cout << "Skill Used: "<<this->skillName<<endl;

  if (!this->specifiedReciever){
    std::vector<state::Character*> intermediary= room->getMonsterTeam()->getTeam();
    this->receiver=intermediary[0];
  } else {
    std::vector<state::Character*> intermediary= room->getMonsterTeam()->getTeam();
    std::vector<state::Character*> intermediary2= room->getHeroTeam()->getTeam();
    if (room->getMonsterTeam()->getPos(this->receiverName)!=1010){
      this->receiver=intermediary[room->getMonsterTeam()->getPos(this->receiverName)];
    } else{
      this->receiver=intermediary2[room->getHeroTeam()->getPos(this->receiverName)];
    }

  }



    state::Skills* s = new state::Skills(attacker,this->receiver);

    s->UseSkill(this->skillName,attacker,this->receiver);
    cout <<this->receiver->getName() <<" life: "<< this->receiver->getLife()<<endl;
    if (this->receiver->getLife() == 0){
      cout << this->receiver->getName();
      cout << " died" << endl;
      if (!this->receiver->isMonster()){
        state::Team* newTeam =room->getMonsterTeam();
        newTeam->removeFromTeam(this->receiver);
        room->setMonsterTeam(newTeam);
      } else {
        state::Team* newTeam =room->getHeroTeam();
        newTeam->removeFromTeam(this->receiver);
        room->setHeroTeam(newTeam);
      }
    }


  state->getGrid()->replaceElement(room,"Room",0);


}

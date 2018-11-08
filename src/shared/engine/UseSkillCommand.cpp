#include "UseSkillCommand.h"
#include <iostream>

using namespace std;
using namespace engine;

//Constructor
UseSkillCommand::UseSkillCommand (){
  this->commandTypeId = UseSkill;
}
UseSkillCommand::UseSkillCommand (std::string skillName,state::Character* receiver){
  this->commandTypeId = UseSkill;
  this->skillName = skillName;
  this->receiver = receiver;
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
  std::vector<std::string> skillList = attacker->getSkillList();
  for (uint i=0;i< skillList.size();i++){
    if (skillList[i].find(this->skillName) != std::string::npos && skillList[i].find("Attack") != std::string::npos){
      state::Skills* s = new state::Skills(attacker,this->receiver);
      s->Attack(attacker,this->receiver);
      if (this->receiver->getLife() == 0){
        cout << this->receiver->getName();
        cout << " died" << endl;
        if (this->receiver->isMonster()){
          state::Team* newTeam =room->getMonsterTeam();
          newTeam->removeFromTeam(this->receiver);
          room->setMonsterTeam(newTeam);
        } else {
          state::Team* newTeam =room->getHeroTeam();
          newTeam->removeFromTeam(this->receiver);
          room->setHeroTeam(newTeam);
        }

      }
    }
  }
  state->getGrid()->replaceElement(room,"Room",0);
  state->Operator();


}

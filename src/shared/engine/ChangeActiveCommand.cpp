#include "ChangeActiveCommand.h"
#include <iostream>

using namespace std;
using namespace engine;

//Constructor
ChangeActiveCommand::ChangeActiveCommand (){
  this->commandTypeId = ChangeActive;
}
//Destructor
ChangeActiveCommand::~ChangeActiveCommand (){
}
//Operations
CommandTypeId ChangeActiveCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void ChangeActiveCommand::execute (state::State* state){
  state::Room* room = (state::Room*) state->getGrid()->get(0,0);
  std::vector<std::pair<bool,std::string>> Order = state->getOrder();
  bool skip =false;
  if (room->getMonsterTeam()->getTeam().size() == 0){
    cout << "The room is empty" << endl;
    room->setIsEmpty(true);
  } else{
      if (Order.size() ==0){
        cout << "Recalculate the order for the next turn" << endl;
      } else {
        Order.push_back(Order[0]);
        Order.erase(Order.begin());
        if (!std::get<0>(Order[0])){

          state::Character* newActive;
          std::vector<state::Character*> intermediary=room->getHeroTeam()->getTeam();
          int pos = room->getHeroTeam()->getPos(std::get<1>(Order[0]));
          // cout << "Change Active: "<<std::get<1>(Order[0])<<" Pos: "<< pos << endl;
          if(pos != 1010){
            state->setActiveChara(Order[0]);
            newActive = intermediary[pos];
            room->setActive(newActive);
            state->getGrid()->replaceElement(room,"Room",0);
            state->setOrder(Order);
          } else {
            skip =true;
          }

        } else {
          state::Character* newActive;
          std::vector<state::Character*> intermediary=room->getMonsterTeam()->getTeam();
          int pos = room->getMonsterTeam()->getPos(std::get<1>(Order[0]));

          if(pos != 1010){
            state->setActiveChara(Order[0]);
            newActive = intermediary[pos];
            room->setActive(newActive);
            state->getGrid()->replaceElement(room,"Room",0);
            state->setOrder(Order);
          } else {
            skip =true;
          }
        }
      }

       if (skip){
         Order.erase(Order.begin());
         if (!std::get<0>(Order[0])){

           state::Character* newActive;
           std::vector<state::Character*> intermediary=room->getHeroTeam()->getTeam();
           int pos = room->getHeroTeam()->getPos(std::get<1>(Order[0]));

           state->setActiveChara(Order[0]);
           newActive = intermediary[pos];
           room->setActive(newActive);
           state->getGrid()->replaceElement(room,"Room",0);
           state->setOrder(Order);


         } else {
           state::Character* newActive;
           std::vector<state::Character*> intermediary=room->getMonsterTeam()->getTeam();
           int pos = room->getMonsterTeam()->getPos(std::get<1>(Order[0]));

           state->setActiveChara(Order[0]);
           newActive = intermediary[pos];
           room->setActive(newActive);
           state->getGrid()->replaceElement(room,"Room",0);
           state->setOrder(Order);
         }
       }
  }
}
void ChangeActiveCommand::executeInv (state::State* state){

  state::Room* room = (state::Room*) state->getGrid()->get(0,0);
  //Reversing Order
  state->ReverseOrder();
  //Reversed Order
  std::vector<std::pair<bool,std::string>> Order = state->getOrder();
  room->ResurectChara(std::get<1>(Order[0]));

  bool skip =false;
  if (room->getMonsterTeam()->getTeam().size() == 0){
    cout << "The room is empty" << endl;
    room->setIsEmpty(true);
  } else{
      if (Order.size() ==0){
        cout << "Recalculate the order for the next turn" << endl;
      } else {
        Order.push_back(Order[0]);
        Order.erase(Order.begin());
        if (!std::get<0>(Order[0])){

          state::Character* newActive;
          std::vector<state::Character*> intermediary=room->getHeroTeam()->getTeam();
          int pos = room->getHeroTeam()->getPos(std::get<1>(Order[0]));
          // cout << "Change Active: "<<std::get<1>(Order[0])<<" Pos: "<< pos << endl;
          if(pos != 1010){
            state->setActiveChara(Order[0]);
            newActive = intermediary[pos];
            room->setActive(newActive);
            state->getGrid()->replaceElement(room,"Room",0);
            state->setOrder(Order);
          } else {
            skip =true;
          }
          cout << "New Active: "<<newActive->getName()<<endl;
        } else {
          state::Character* newActive;
          std::vector<state::Character*> intermediary=room->getMonsterTeam()->getTeam();
          int pos = room->getMonsterTeam()->getPos(std::get<1>(Order[0]));

          if(pos != 1010){
            state->setActiveChara(Order[0]);
            newActive = intermediary[pos];
            room->setActive(newActive);
            state->getGrid()->replaceElement(room,"Room",0);
            state->setOrder(Order);
          } else {
            skip =true;
          }
          cout << "New Active: "<<newActive->getName()<<endl;
        }
      }

       if (skip){
         Order.erase(Order.begin());
         if (!std::get<0>(Order[0])){

           state::Character* newActive;
           std::vector<state::Character*> intermediary=room->getHeroTeam()->getTeam();
           int pos = room->getHeroTeam()->getPos(std::get<1>(Order[0]));

           state->setActiveChara(Order[0]);
           newActive = intermediary[pos];
           room->setActive(newActive);
           state->getGrid()->replaceElement(room,"Room",0);
           state->setOrder(Order);


         } else {
           state::Character* newActive;
           std::vector<state::Character*> intermediary=room->getMonsterTeam()->getTeam();
           int pos = room->getMonsterTeam()->getPos(std::get<1>(Order[0]));

           state->setActiveChara(Order[0]);
           newActive = intermediary[pos];
           room->setActive(newActive);
           state->getGrid()->replaceElement(room,"Room",0);
           state->setOrder(Order);
         }
       }
  }
}

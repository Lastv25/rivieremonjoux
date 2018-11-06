// #include "CreateRoomCommand.h"
// #include <iostream>
// #include <fstream>
//
// using namespace std;
// using namespace engine;
//
// CreateRoomCommand::CreateRoomCommand ():Command(){
//   this->commandTypeId = CreateRoom;
// }
// CreateRoomCommand::~CreateRoomCommand (){
// }
// CommandTypeId CreateRoomCommand::getCommandTypeId (){
//   return this->commandTypeId;
// }
// void CreateRoomCommand::execute (state::State* state){
//   state::Dungeon* d = (state::Dungeon*) state->getGrid()->get(0,0);
//
//   if (d->getRoomList().size() == 0){
//     cout << "The Dungeon is Cleared" << endl;
//   } else {
//     state->getGrid()->replaceElement(new state::Room(d->getHeroTeam(),d->getRoomList()[0],std::get<0>(state->getActiveChara()),std::get<1>(state->getActiveChara())),"Room",0);
//     state->getChar()->add(state->getGrid()->get(0,0),"Dungeon");
//   }
//
// }

#include "ChooseDungeonCommand.h"
#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;
using namespace engine;
using namespace state;

//Constructor
ChooseDungeonCommand::ChooseDungeonCommand ():Command(){
  this->commandTypeId = ChooseDungeon;
}
ChooseDungeonCommand::ChooseDungeonCommand (std::string choice):Command(){
  this->commandTypeId = ChooseDungeon;
  this->chosenDungeon = choice;
}
//Destructor
ChooseDungeonCommand::~ChooseDungeonCommand (){
}
CommandTypeId ChooseDungeonCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void ChooseDungeonCommand::execute (state::State* states){
  std::string dungeonName = "res/Dungeons/"+this->chosenDungeon+".txt";
  std::ifstream fileread(dungeonName);
  std::map<std::string,state::Team*> rooms;


  for (std::string line; getline(fileread,line);){


    std::size_t current=0;
    std::size_t previous=0;
    current = line.find(",");
    std::vector<std::string> out;
    while(current!=std::string::npos){

      out.push_back(line.substr(previous,current-previous));
      previous = current +1;
      current = line.find(",",previous);
    }
    out.push_back(line.substr(previous,current-previous));

    state::Team* MonsterTeam = new state::Team();

    for (uint i=0; i<out.size();i++){
      if(out[i].find("Blob")!=std::string::npos){
        state::Blob* b = new state::Blob(2,1,1,1,5,"Blob");
        MonsterTeam->addToTeam(b);
      } else if(out[i].find("Sorcerer")!=std::string::npos){
        state::Sorcerer* s = new state::Sorcerer(5,2,2,10,30,"Sorcerer");
        MonsterTeam->addToTeam(s);
      } else if(out[i].find("DarkKnight")!=std::string::npos){
        state::DarkKnight* d = new state::DarkKnight(5,2,2,10,30,"DarkKnight");
        MonsterTeam->addToTeam(d);
      }

      rooms[out[0]]=MonsterTeam;

    }
  }

  Dungeon* dungeon = (Dungeon*) states->getGrid()->get(0,0);
  dungeon->setRoomList(rooms);
  states->getGrid()->replaceElement(dungeon,"Dungeon",0);
  states->Operator();

}

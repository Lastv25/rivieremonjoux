#include "ChooseDungeonCommand.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include "../state/Village.h"
#include "../state/Team.h"
#include "../state/Sorcerer.h"
#include "../state/Blob.h"
#include "../state/DarkKnight.h"
#include "../state/Dungeon.h"
namespace state {
  class Village;
  class Team;
  class Sorcerer;
  class Blob;
  class DarkKnight;
  class Dungeon;
}
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

  if (fileread.good()){
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
          state::Blob* b = new state::Blob(20,1,2,1,5,"Blob");
          MonsterTeam->addToTeam(b);
        } else if(out[i].find("Sorcerer")!=std::string::npos){
          state::Sorcerer* s = new state::Sorcerer(10,2,3,15,10,"Sorcerer");
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
    dungeon->setCurrentRoom("0");
    states->getGrid()->replaceElement(dungeon,"Dungeon",0);
    states->setDungeonExists(true);

  } else{
    cout << "This dungeon is under construction by the goblin developpers. It is not accessible yet" << endl;
    states->setDungeonExists(false);
  }
}
void ChooseDungeonCommand::executeInv (state::State* state){
}

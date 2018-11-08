#include <iostream>
#include <SFML/Graphics.hpp>
#include "ElementTabLayer.h"
#include <typeinfo>


using namespace std;
using namespace render;
using namespace sf;




ElementTabLayer::ElementTabLayer (state::ElementTab* elementTab):Layer(){
  this->elementTab=elementTab;
  this->text="None";
}
ElementTabLayer::~ElementTabLayer (){
}

state::ElementTab* ElementTabLayer::getElementTabNames (){
  return this->elementTab;
}
void ElementTabLayer::setElementTab (state::ElementTab* newElementTabNames){
  this->elementTab = newElementTabNames;
}
void ElementTabLayer::setTitle (std::string title){
  this->title = title;
}
std::string ElementTabLayer::getTitle (){
  return this->title;
}
void ElementTabLayer::setText (std::string text){
  this->text = text;
}
std::string ElementTabLayer::getText (){
  return this->text;
}

void ElementTabLayer::getElementTabTextures (){
  for (uint index=0; index<this->elementTab->getSize(); index++ ){
    cout <<this->elementTab->getElementType(index) << endl;
    if (this->elementTab->getElementType(index).find("Room") != std::string::npos){
      float testTeamMonster = 0;
      float testTeamMonster2 = 0;
      //cout << "Room found" << endl;
      RoomDisplay* droom = new RoomDisplay(this->elementTab->get(index,0));
      droom->getCharacter();
      for (uint i=0; i<droom->getRoomImages().size(); i++ ){
        if (droom->getRoomImages()[i].find("background") != std::string::npos){
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          float cords[]={0,0,1,1};
          addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
        } else if (droom->getRoomImages()[i].find("map") != std::string::npos){
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          float cords[]={550,750,1,1};
          addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
        } else if (droom->getRoomImages()[i].find("box") != std::string::npos){
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          float cords[]={0,750,1,1};
          addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
        } else {
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          if (testTeamMonster < 3) {
            if(droom->getRoomImages()[i].find(droom->getActiveName()) != std::string::npos){
              float cords[]={50.f+testTeamMonster*150,400,1,1};
              addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
            } else {
              float cords[]={50.f+testTeamMonster*150,450,0.8,0.8};
              addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
            }
          } else {
            if(droom->getRoomImages()[i].find(droom->getActiveName()) != std::string::npos){
              float cords[]={1000.f+testTeamMonster*150,400,-1,1};
              addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
              testTeamMonster2 +=1;
            } else {
              float cords[]={1050.f+testTeamMonster2*150,450,-0.8,0.8};
              addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
              testTeamMonster2 +=1;
            }
          }
          testTeamMonster +=1;

        }
      }
      setTitle(droom->getDisplayText());
      setText(droom->getCharacterStats());
      std::vector<float> txtcoords;
      txtcoords.push_back(50.f);
      txtcoords.push_back(800.f);
      setTextcoords(txtcoords);
    } else if (this->elementTab->getElementType(index).find("Village") != std::string::npos){
      //cout << "Village found" << endl;
      VillageDisplay* dvillage = new VillageDisplay();
      Surface* s= new Surface(100,100,100,100);
      s->loadTexture(dvillage->getVillageImages()[0]);
      s->setSprite();
      setSurface(s);
      setTitle(dvillage->getDisplayText());
    } else if (this->elementTab->getElementType(index).find("Dungeon") != std::string::npos){
      //cout << "Dungeon found" << endl;
      DungeonDisplay* ddungeon = new DungeonDisplay(this->elementTab->get(index,0));
      setTitle(ddungeon->getDisplayText());
      setText(ddungeon->getDungeonList());
      std::vector<float> txtcoords;
      txtcoords.push_back(500.f);
      txtcoords.push_back(400.f);
      setTextcoords(txtcoords);
    } else if (this->elementTab->getElementType(index).find("Tavern") != std::string::npos){
      //cout << "Tavern found" << endl;
    } else if (this->elementTab->getElementType(index).find("Shop") != std::string::npos){
      //cout << "Shop found" << endl;
    } else {
      //cout << "Invelid element Tab" << endl;
    }
  }
}

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
std::vector<std::pair<std::string,std::vector<float>>>  ElementTabLayer::getButtons (){
  return this->buttons;
}
void  ElementTabLayer::setButtons (std::vector<std::pair<std::string,std::vector<float>>> newButtons){
  this->buttons=newButtons ;
}
void  ElementTabLayer::addButton (std::pair<std::string,std::vector<float>> newButton){
  this->buttons.push_back(newButton) ;
}
std::pair<std::string,std::vector<float>>  ElementTabLayer::getButton (int i){
  return this->buttons.at(i);
}
std::string ElementTabLayer::getButtonFont (){
  return this->buttonsFont;
}
std::string ElementTabLayer::getButtonSprite (){
  return this->buttonsSprite;
}
std::vector<float> ElementTabLayer::getButtonPosScale (int i){
  return this->buttonsPosScale[i];
}
void ElementTabLayer::addButtonScale (float x, float y, float sx, float sy){
  std::vector<float> intermediary;
  intermediary.push_back(x);
  intermediary.push_back(y);
  intermediary.push_back(sx);
  intermediary.push_back(sy);
  this->buttonsPosScale.push_back(intermediary);
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

      Surface* buttonsSurface= new Surface(100,100,100,100);
      buttonsSurface->loadTexture(this->buttonsSprite);
      buttonsSurface->setSprite();
      setButtonSurface(buttonsSurface);
      std::vector<float> bcoords = {50.f,1000.f};
      addButton(std::pair<std::string,std::vector<float>>("Dungeon",bcoords));
      addButtonScale(50.f,1100.f,0.5f,0.5f);

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

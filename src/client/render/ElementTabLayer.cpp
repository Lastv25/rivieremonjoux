#include <iostream>
#include <SFML/Graphics.hpp>
#include "ElementTabLayer.h"


using namespace std;
using namespace render;
using namespace sf;




ElementTabLayer::ElementTabLayer (state::ElementTab* elementTab):Layer(){
  this->elementTab=elementTab;
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

void ElementTabLayer::getElementTabTextures (){
  for (uint index=0; index<this->elementTab->getSize(); index++ ){
    if (this->elementTab->getElementType(index).find("Room") != std::string::npos){
      cout << "Room found" << endl;
      RoomDisplay* droom = new RoomDisplay();
      droom->getCharacter();
      for (uint i=0; i<droom->getRoomImages().size(); i++ ){
        if (droom->getRoomImages()[i].find("background") != std::string::npos){
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          addCoords(std::pair<uint,uint>(0,0));
        } else if (droom->getRoomImages()[i].find("map") != std::string::npos){
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          addCoords(std::pair<uint,uint>(550,750));
        } else if (droom->getRoomImages()[i].find("box") != std::string::npos){
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          addCoords(std::pair<uint,uint>(0,750));
        } else {
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(droom->getRoomImages()[i]);
          s->setSprite();
          setSurface(s);
          addCoords(std::pair<uint,uint>(150,400));
        }
      }
      setTitle(droom->getDisplayText());
    } else if (this->elementTab->getElementType(index).find("Village") != std::string::npos){
      cout << "Village found" << endl;
      VillageDisplay* dvillage = new VillageDisplay();
      Surface* s= new Surface(100,100,100,100);
      s->loadTexture(dvillage->getVillageImages()[0]);
      s->setSprite();
      setSurface(s);
      setTitle(dvillage->getDisplayText());
    } else if (this->elementTab->getElementType(index).find("Tavern") != std::string::npos){
      cout << "Tavern found" << endl;
    } else if (this->elementTab->getElementType(index).find("Shop") != std::string::npos){
      cout << "Shop found" << endl;
    } else {
      cout << "Invelid element Tab" << endl;
    }
  }
}

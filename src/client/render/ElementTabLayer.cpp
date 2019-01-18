#include <iostream>
#include <SFML/Graphics.hpp>
#include "ElementTabLayer.h"
#include <typeinfo>
#include "../../shared/state/Dungeon.h"

using namespace std;
using namespace render;
using namespace sf;
namespace state{
  class Dungeon;
}



ElementTabLayer::ElementTabLayer (state::ElementTab* elementTab):Layer(){
  this->elementTab=elementTab;
  this->text="None";
  this->alreadyDisplayedOnce="None";

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
bool ElementTabLayer::getSkillUsed (){
  return this->skillUsed;
}
void ElementTabLayer::setSkillUsed (bool isUsed){
  this->skillUsed=isUsed;
}
void ElementTabLayer::setAlreadyDisplayedOnce (std::string newDisplay){
  this->alreadyDisplayedOnce=newDisplay;
}
std::string ElementTabLayer::getAlreadyDisplayedOnce (){
  return this->alreadyDisplayedOnce;
}
std::string ElementTabLayer::getElementTabTextures (){

  std::string output;

  for (uint index=0; index<this->elementTab->getSize(); index++ ){

    //cout << "Already Displayed: "<<this->alreadyDisplayedOnce << endl;
    if (this->elementTab->getElementType(index).find("Room") != std::string::npos){
      output = "Room";
      if (this->alreadyDisplayedOnce.find("Room") == std::string::npos ) {

        float testTeamMonster = 0;
        float testTeamMonster2 = 0;
        cout << "Room found" << endl;

        RoomDisplay* droom = new RoomDisplay(this->elementTab->get(index,0));
        droom->getCharacter();
        for (uint i=0; i<droom->getRoomImages().size(); i++ ){
          //cout << droom->getRoomImages()[i] <<endl;
          if (droom->getRoomImages()[i].find("background") != std::string::npos){
            Surface* s= new Surface(100,100,100,100);
            s->loadTexture(droom->getRoomImages()[i]);
            s->setSprite();
            setSurface(s);
            float cords[]={0,0,1,1};
            addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
          } else if (droom->getRoomImages()[i].find("map") != std::string::npos){
            // Surface* s= new Surface(100,100,100,100);
            // s->loadTexture(droom->getRoomImages()[i]);
            // s->setSprite();
            // setSurface(s);
            // float cords[]={550,750,1,1};
            // addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
          } else if (droom->getRoomImages()[i].find("box") != std::string::npos){
            // Surface* s= new Surface(100,100,100,100);
            // s->loadTexture(droom->getRoomImages()[i]);
            // s->setSprite();
            // setSurface(s);
            // float cords[]={0,750,1,1};
            // addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
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
                //cout <<testTeamMonster<<endl;
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
        //cout << droom->getCharacterStats() << endl;
        std::vector<float> txtcoords;
        txtcoords.push_back(50.f);
        txtcoords.push_back(800.f);
        setTextcoords(txtcoords);

        setDrawText(true);
        setDrawSprite(true);

        if (getButtonsSurface().size()>1){
          this->buttonsSurface.clear();
          this->buttons.clear();
        }

        Surface* buttonsSurface= new Surface(100,100,100,100);
        buttonsSurface->loadTexture(this->buttonsSprite);
        buttonsSurface->setSprite();
        setButtonSurface(buttonsSurface);
        std::vector<float> bcoords = {1200.f,50.f};
        addButton(std::pair<std::string,std::vector<float>>("Back",bcoords));
        addButtonScale(50.f,1100.f,0.5f,0.5f);

        if (droom->getActive()->getSkillList().size()!=1){
          for (uint i=0; i<droom->getActive()->getSkillList().size();i++){
            Surface* buttonsSurface2= new Surface(100,100,100,100);
            buttonsSurface2->loadTexture(this->buttonsSprite);
            buttonsSurface2->setSprite();
            setButtonSurface(buttonsSurface2);
            std::vector<float> bcoords2 = {450.f,750.f+i*100};
            addButton(std::pair<std::string,std::vector<float>>(droom->getActive()->getSkillList()[i],bcoords2));
            addButtonScale(50.f,1100.f,0.5f,0.5f);
          }
        } else {
          Surface* buttonsSurface2= new Surface(100,100,100,100);
          buttonsSurface2->loadTexture(this->buttonsSprite);
          buttonsSurface2->setSprite();
          setButtonSurface(buttonsSurface2);
          std::vector<float> bcoords2 = {450.f,750.f};
          addButton(std::pair<std::string,std::vector<float>>(droom->getActive()->getSkillList()[0],bcoords2));
          addButtonScale(50.f,1100.f,0.5f,0.5f);
        }


        Surface* buttonsSurface3= new Surface(100,100,100,100);
        buttonsSurface3->loadTexture(this->buttonsSprite);
        buttonsSurface3->setSprite();
        setButtonSurface(buttonsSurface3);
        std::vector<float> bcoords3 = {100.f,50.f};
        addButton(std::pair<std::string,std::vector<float>>("Next Turn",bcoords3));
        addButtonScale(50.f,1100.f,0.5f,0.5f);

        if (droom->getIsEmpty()){
          Surface* buttonsSurface= new Surface(100,100,100,100);
          buttonsSurface->loadTexture(this->buttonsSprite);
          buttonsSurface->setSprite();
          setButtonSurface(buttonsSurface);
          std::vector<float> bcoords = {700.f,400.f};
          addButton(std::pair<std::string,std::vector<float>>("Next Room",bcoords));
          addButtonScale(50.f,1100.f,0.5f,0.5f);
        }
        //cout << "Skill Used: "<<getSkillUsed()<<endl;
        if (getSkillUsed()){
          
          if (droom->getActive()->isMonster()){

            for (uint i=0;i< droom->getMonsterTeam()->getTeam().size();i++){
              cout << droom->getMonsterTeam()->getTeam()[i]->getName() <<endl;
              Surface* buttonsSurface= new Surface(100,100,100,100);
              buttonsSurface->loadTexture(this->buttonsSpriteSkills);
              buttonsSurface->setSprite();
              setButtonSurface(buttonsSurface);
              std::vector<float> bcoords = {800.f,750.f+i*100};
              addButton(std::pair<std::string,std::vector<float>>(droom->getMonsterTeam()->getTeam()[i]->getName(),bcoords));
              addButtonScale(50.f,1100.f,0.5f,0.5f);
            }
          } else{

            for (uint i=0;i< droom->getHeroTeam()->getTeam().size();i++){
              cout << droom->getMonsterTeam()->getTeam()[i]->getName() <<endl;
              Surface* buttonsSurface= new Surface(100,100,100,100);
              buttonsSurface->loadTexture(this->buttonsSpriteSkills);
              buttonsSurface->setSprite();
              setButtonSurface(buttonsSurface);
              std::vector<float> bcoords = {800.f,750.f+i*100};
              addButton(std::pair<std::string,std::vector<float>>(droom->getHeroTeam()->getTeam()[i]->getName(),bcoords));
              addButtonScale(50.f,1100.f,0.5f,0.5f);
            }
          }
        }

        this->alreadyDisplayedOnce = "Room";
        setSkillUsed(false);
      }

    } else if (this->elementTab->getElementType(index).find("Village") != std::string::npos){
      output = "Village";
      if (this->alreadyDisplayedOnce.find("Village") == std::string::npos) {
        cout << "Village found" << endl;


        VillageDisplay* dvillage = new VillageDisplay();
        Surface* s= new Surface(100,100,100,100);
        s->loadTexture(dvillage->getVillageImages()[0]);
        s->setSprite();
        setSurface(s);
        setTitle(dvillage->getDisplayText());
        setDrawText(false);
        setDrawSprite(true);

        if (getButtonsSurface().size()>=1){
          this->buttonsSurface.clear();
          this->buttons.clear();
        }


        Surface* buttonsSurface= new Surface(100,100,100,100);
        buttonsSurface->loadTexture(this->buttonsSprite);
        buttonsSurface->setSprite();
        setButtonSurface(buttonsSurface);
        std::vector<float> bcoords = {50.f,1000.f};
        addButton(std::pair<std::string,std::vector<float>>("Dungeon",bcoords));
        addButtonScale(50.f,1100.f,0.5f,0.5f);

        Surface* buttonsSurface1= new Surface(100,100,100,100);
        buttonsSurface1->loadTexture(this->buttonsSprite);
        buttonsSurface1->setSprite();
        setButtonSurface(buttonsSurface1);
        std::vector<float> bcoords1 = {1000.f,1000.f};
        addButton(std::pair<std::string,std::vector<float>>("Tavern",bcoords1));
        addButtonScale(50.f,1100.f,0.5f,0.5f);
        this->alreadyDisplayedOnce = "Village";

      }

    } else if (this->elementTab->getElementType(index).find("Dungeon") != std::string::npos){
      output = "Dungeon";
      if (this->alreadyDisplayedOnce.find("Dungeon") == std::string::npos) {


        cout << "Dungeon found" << endl;
        DungeonDisplay* ddungeon = new DungeonDisplay(this->elementTab->get(index,0));
        setTitle(ddungeon->getDisplayText());
        setDrawText(false);
        setDrawSprite(false);

        if (getButtonsSurface().size()>1){
          this->buttonsSurface.clear();
          this->buttons.clear();
        }

        std::vector<std::string> mapNames=ddungeon->getDungeonList();
        for (uint i=0;i< mapNames.size();i++){

          Surface* buttonsSurface= new Surface(100,100,100,100);
          buttonsSurface->loadTexture(this->buttonsSprite);
          buttonsSurface->setSprite();



          if (i+1<=getButtonsSurface().size()){

            this->buttonsSurface.at(i)=buttonsSurface;
            std::vector<float> bcoords = {700.f,400.f+100*i};
            this->buttons.at(i)=std::pair<std::string,std::vector<float>>(mapNames[i],bcoords);
            std::vector<float> intermediary;
            intermediary.push_back(50.f);
            intermediary.push_back(1100.f);
            intermediary.push_back(0.5f);
            intermediary.push_back(0.5f);
            this->buttonsPosScale.at(i)=intermediary;
          } else {
            setButtonSurface(buttonsSurface);
            std::vector<float> bcoords = {700.f,400.f+100*i};
            addButton(std::pair<std::string,std::vector<float>>(mapNames[i],bcoords));
            addButtonScale(50.f,1100.f,0.5f,0.5f);
          }

        }

        Surface* buttonsSurface= new Surface(100,100,100,100);
        buttonsSurface->loadTexture(this->buttonsSprite);
        buttonsSurface->setSprite();
        setButtonSurface(buttonsSurface);
        std::vector<float> bcoords = {1050.f,1000.f};
        addButton(std::pair<std::string,std::vector<float>>("Back",bcoords));
        addButtonScale(50.f,1100.f,0.5f,0.5f);

        this->alreadyDisplayedOnce = "Dungeon";
      }
    } else if (this->elementTab->getElementType(index).find("Tavern") != std::string::npos){
      output = "Tavern";
      if (this->alreadyDisplayedOnce.find("Tavern") == std::string::npos) {
        cout << "Tavern found" << endl;


        TavernDisplay* dtavern = new TavernDisplay(this->elementTab->get(index,0));

        setTitle(dtavern->getDisplayText());
        // setText(dtavern->getText());
        setText(dtavern->TavernCharaText());

        std::vector<float> txtcoords;
        // txtcoords.push_back(50.f);
        // txtcoords.push_back(800.f);
        txtcoords.push_back(100.f);
        txtcoords.push_back(600.f);
        setTextcoords(txtcoords);

        setDrawText(true);
        setDrawSprite(true);

        int decalage =0 ;
        for (uint i=0; i<dtavern->getTavernImages().size(); i++ ){
          if (dtavern->getTavernImages()[i].find("box") != std::string::npos){
            // Surface* s= new Surface(100,100,100,100);
            // s->loadTexture(dtavern->getTavernImages()[i]);
            // s->setSprite();
            // setSurface(s);
            // float cords[]={0,0,1,1};
            // addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
          } else {
            Surface* s= new Surface(100,100,100,100);
            s->loadTexture(dtavern->getTavernImages()[i]);
            s->setSprite();
            setSurface(s);
            float cords[]={200.f+300*decalage,250,1,1};
            addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
            decalage =decalage+1;
          }
        }
        decalage =0 ;
        for (uint i=0; i<dtavern->getTeam().size(); i++ ){
          Surface* s= new Surface(100,100,100,100);
          s->loadTexture(dtavern->getTeam()[i]);
          s->setSprite();
          setSurface(s);
          float cords[]={300.f+300*decalage,800,0.5,0.5};
          addCoords(std::vector<float>(cords,cords+sizeof(cords)/sizeof(float)));
          decalage =decalage+1;
        }

        if (getButtonsSurface().size()>1){
          this->buttonsSurface.clear();
          this->buttons.clear();
        }

        //for (uint i=0; i<dtavern->getTeamNames().size(); i++ ){cout <<dtavern->getTeamNames()[i]<<endl;}

        Surface* buttonsSurface= new Surface(100,100,100,100);
        buttonsSurface->loadTexture(this->buttonsSprite);
        buttonsSurface->setSprite();
        setButtonSurface(buttonsSurface);
        std::vector<float> bcoords = {1050.f,1000.f};
        addButton(std::pair<std::string,std::vector<float>>("Back",bcoords));
        addButtonScale(50.f,1100.f,0.5f,0.5f);

        for (uint i=0;i<4;i++){
          Surface* buttonsSurface= new Surface(100,100,100,100);
          buttonsSurface->loadTexture(this->buttonsSprite);
          buttonsSurface->setSprite();
          setButtonSurface(buttonsSurface);
          std::vector<float> bcoords = {200.f+300*i,500};
          addButton(std::pair<std::string,std::vector<float>>("Add",bcoords));
          addButtonScale(50.f,1100.f,0.5f,0.5f);
        }
        for (uint i=0;i<dtavern->getTeam().size();i++){
          Surface* buttonsSurface= new Surface(100,100,100,100);
          buttonsSurface->loadTexture(this->buttonsSprite);
          buttonsSurface->setSprite();
          setButtonSurface(buttonsSurface);
          std::vector<float> bcoords = {300.f+300*i,900};
          addButton(std::pair<std::string,std::vector<float>>("Remove",bcoords));
          addButtonScale(50.f,1100.f,0.5f,0.5f);
        }

        this->alreadyDisplayedOnce = "Tavern";
      }

    } else if (this->elementTab->getElementType(index).find("Shop") != std::string::npos){
      //cout << "Shop found" << endl;
    } else if (this->elementTab->getElementType(index).find("Menu") != std::string::npos){
      output = "Menu";
      if (this->alreadyDisplayedOnce.find("Menu") == std::string::npos) {
        cout << "Menu found" << endl;

        MenuDisplay* dmenu = new MenuDisplay();
        Surface* s= new Surface(100,100,100,100);
        s->loadTexture(dmenu->getMenuImages()[0]);
        s->setSprite();
        setSurface(s);
        setTitle(dmenu->getDisplayText());
        setDrawText(false);
        setDrawSprite(true);

        if (getButtonsSurface().size()>=1){
          this->buttonsSurface.clear();
          this->buttons.clear();
        }


        Surface* buttonsSurface= new Surface(100,100,100,100);
        buttonsSurface->loadTexture(this->buttonsSprite);
        buttonsSurface->setSprite();
        setButtonSurface(buttonsSurface);
        std::vector<float> bcoords = {100.f,500.f};
        addButton(std::pair<std::string,std::vector<float>>("1 Player",bcoords));
        addButtonScale(100.f,1100.f,0.5f,0.5f);

        Surface* buttonsSurface1= new Surface(100,100,100,100);
        buttonsSurface1->loadTexture(this->buttonsSprite);
        buttonsSurface1->setSprite();
        setButtonSurface(buttonsSurface1);
        std::vector<float> bcoords1 = {900.f,500.f};
        addButton(std::pair<std::string,std::vector<float>>("2 Players",bcoords1));
        addButtonScale(50.f,1100.f,0.5f,0.5f);
        this->alreadyDisplayedOnce = "Menu";
      }
    } else {
      //cout << "Invelid element Tab" << endl;
    }
  }
  return output;
}

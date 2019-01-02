#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <chrono>
#include <thread>
#include "../../shared/ai/RandomAI.h"
#include "../../shared/ai/HeuristicAI.h"
#include "../../shared/ai/DeepAI.h"
namespace ai {
  class RandomAI;
  class HeuristicAI;
  class DeepAI;
}
using namespace std;
using namespace render;
using namespace sf;
using namespace std::chrono;
using namespace std::this_thread;

//Constructor
Scene::Scene (){
}

Scene::Scene (state::State* state,engine::Button* button,ai::RandomAI* rai){
  this->raiType=true;
  this->state = state;
  this->tabLayer = new ElementTabLayer(state->getGrid());
  this->buttonPressed = button;
  this->rai = rai;

}
Scene::Scene (state::State* state,engine::Button* button,ai::HeuristicAI* hai){
  this->haiType=true;
  this->state = state;
  this->tabLayer = new ElementTabLayer(state->getGrid());
  this->buttonPressed = button;
  this->hai = hai;
}
Scene::Scene (state::State* state,engine::Button* button,ai::DeepAI* dai){
  this->daiType=true;
  this->state = state;
  this->tabLayer = new ElementTabLayer(state->getGrid());
  this->buttonPressed = button;
  this->dai = dai;
}
//Destructor
Scene::~Scene (){
}

//Operations
void Scene::stateChanged (state::State* state){
  this->state = state;
  this->stateChangedBool = true;
}
engine::Button* Scene::getButtonPressed (){
  return this->buttonPressed;
}
void Scene::updateScene(){
}
void Scene::TavernPersCoords (float x, float y){
  if (200.f<x && x<350.f && 500.f<y && y<550.f){
    this->buttonPressed->setAdditionalParam("Tank");
  } else if (500.f<x && x<650.f && 500.f<y && y<550.f){
    this->buttonPressed->setAdditionalParam("Mage");
  } else if (800.f<x && x<950.f && 500.f<y && y<550.f){
    this->buttonPressed->setAdditionalParam("Assassin");
  } else if (1100.f<x && x<1250.f && 500.f<y && y<550.f){
    this->buttonPressed->setAdditionalParam("Range");
  } else if (300.f<x && x<450.f && 900.f<y && y<950.f){
    this->buttonPressed->setAdditionalParam("1");
  } else if (600.f<x && x<750.f && 900.f<y && y<950.f){
    this->buttonPressed->setAdditionalParam("2");
  } else if (900.f<x && x<1050.f && 900.f<y && y<950.f){
    this->buttonPressed->setAdditionalParam("3");
  }
}
void Scene::eventHandler (sf::Event event){
  if (event.type == sf::Event::MouseButtonPressed){
    if(event.mouseButton.button == sf::Mouse::Left){
      if (this->clickSkill){
        for (uint i=0;i<this->tabLayer->getButtonsSurface().size();i++){
          float x =std::get<1>(this->tabLayer->getButton(i))[0];
          float y =std::get<1>(this->tabLayer->getButton(i))[1];
          if (x < event.mouseButton.x && event.mouseButton.x < x+200 && y < event.mouseButton.y && event.mouseButton.y< y+50){
            // cout << "mouse x: " <<event.mouseButton.x ;
            // cout << "  mouse y: " <<event.mouseButton.y ;
            // cout << " Button: " <<std::get<0>(this->tabLayer->getButton(i))<< endl;
            this->buttonPressed->setCommand(this->buttonPressed->getSkillName());
            this->buttonPressed->setAdditionalParam(std::get<0>(this->tabLayer->getButton(i)));
            this->stateChangedBool = true;
            this->tabLayer->setSkillUsed(false);
            this->tabLayer->setAlreadyDisplayedOnce("None");
            this->buttonPressed->sendToEngine();
            this->clickSkill= false;
          }
        }
      } else {
        for (uint i=0;i<this->tabLayer->getButtonsSurface().size();i++){
          //cout << this->tabLayer->getButtonsSurface().size() << endl;
          float x =std::get<1>(this->tabLayer->getButton(i))[0];
          float y =std::get<1>(this->tabLayer->getButton(i))[1];
          if (x < event.mouseButton.x && event.mouseButton.x < x+200 && y < event.mouseButton.y && event.mouseButton.y< y+50){
            // cout << "mouse x: " <<event.mouseButton.x ;
            // cout << "  mouse y: " <<event.mouseButton.y ;
            // cout << " Button: " <<std::get<0>(this->tabLayer->getButton(i))<< endl;
            if (std::get<0>(this->tabLayer->getButton(i)).find("Add")!=std::string::npos || std::get<0>(this->tabLayer->getButton(i)).find("Remove")!=std::string::npos  ){
              this->buttonPressed->setCommand(std::get<0>(this->tabLayer->getButton(i)));
              TavernPersCoords(event.mouseButton.x,event.mouseButton.y);
              this->buttonPressed->sendToEngine();
              this->tabLayer->setAlreadyDisplayedOnce("None");
              this->clickSkill= true;
            }
            else if (std::get<0>(this->tabLayer->getButton(i)).find("Attack")!=std::string::npos || std::get<0>(this->tabLayer->getButton(i)).find("Poison")!=std::string::npos  ){
            //   this->stateChangedBool = true;
              this->buttonPressed->setSkillName(std::get<0>(this->tabLayer->getButton(i)));
              this->tabLayer->setSkillUsed(true);
              this->tabLayer->setAlreadyDisplayedOnce("None");
              this->clickSkill= true;

          } else {
            this->buttonPressed->setCommand(std::get<0>(this->tabLayer->getButton(i)));
            this->buttonPressed->setAdditionalParam(std::get<0>(this->tabLayer->getButton(i)));
            this->buttonPressed->sendToEngine();
            this->stateChangedBool = true;

            if (std::get<0>(this->tabLayer->getButton(i)).find("Next Turn")!=std::string::npos){
               this->tabLayer->setAlreadyDisplayedOnce("None");
            } else if (std::get<0>(this->tabLayer->getButton(i)).find("Next Room")!=std::string::npos ){
              this->stateChangedBool = true;
              this->tabLayer->setAlreadyDisplayedOnce("None");
            }
          }
        }
       }
    }
  }
 }
}
void Scene::updateScreen (sf::RenderWindow* window){
  // cout << this->tabLayer->getAlreadyDisplayedOnce()<<endl;

  sf::Sprite sprite;
  sf::Font font;
  sf::Text text;
  std::string stateType;


  // cout << "Change1: "<<this->state->getChange()<<" test true: "<<true<<endl;
  if (this->stateChangedBool || this->state->getChange()){
    this->tabLayer->clearSurfaces();
    this->stateChangedBool = false;
    window->clear(sf::Color::Black);
    this->hai->setStateType(this->tabLayer->getElementTabTextures());
    this->state->stateChanged();
    this->tabLayer->setAlreadyDisplayedOnce("None");
  }
  // cout << "Change2: "<<this->state->getChange()<<" test true: "<<true<<endl;

  //cout << "state Title: " <<this->tabLayer->getTitle()<< ", taille surface list: " <<this->tabLayer->getSurfaceList().size()<< ", taille ButtonsSurface list: " <<this->tabLayer->getButtonsSurface().size()<<endl;

  font.loadFromFile("res/dc_o.ttf");
  sf::Text title(this->tabLayer->getTitle(),font,50);
  title.move(600.f,100.f);

  //cout << 1;

  if (this->tabLayer->getDrawSprite()){
    //cout <<"sprites"<<endl;
    if (this->tabLayer->getSurfaceList().size() != 1){
      for (uint i=0;i<this->tabLayer->getSurfaceList().size();i++){

         sprite = this->tabLayer->getSurface(i)->getSprite();
         sprite.setPosition(this->tabLayer->getCoords()[i][0],this->tabLayer->getCoords()[i][1]);
         //cout <<"sx: "<<this->tabLayer->getCoords()[i][2]<< " sy: "<<this->tabLayer->getCoords()[i][3]<<endl;
         sprite.scale(this->tabLayer->getCoords()[i][2],this->tabLayer->getCoords()[i][3]);
         window->draw(sprite);
       }
     } else {
       sprite = this->tabLayer->getSurface(0)->getSprite();
       sprite.setScale(1.15f,1.7f);
       window->draw(sprite);
     }
   }


   //cout << 2;
   if (this->tabLayer->getDrawText()){
     //cout <<"text"<<endl;
     if (this->tabLayer->getText().find("None") == std::string::npos){
       text.setString(this->tabLayer->getText());
       text.setFont(font);
       text.setCharacterSize(25);
       text.move(this->tabLayer->getTextcoords()[0],this->tabLayer->getTextcoords()[1]);
       window->draw(text);
       //cout <<"x: "<<this->tabLayer->getTextcoords()[0]<< " y: "<<this->tabLayer->getTextcoords()[1]<<endl;
     }
   }
   //cout << 3;

   if (this->tabLayer->getButtonsSurface().size() != 0){
     //cout <<"buttons"<<endl;
     for (uint i=0;i<this->tabLayer->getButtonsSurface().size();i++){
       sprite = this->tabLayer->getButtonSurface(i)->getSprite();
       float x =std::get<1>(this->tabLayer->getButton(i))[0];
       float y =std::get<1>(this->tabLayer->getButton(i))[1];
       sprite.setPosition(x,y);
       sprite.scale(this->tabLayer->getButtonPosScale(i)[2],this->tabLayer->getButtonPosScale(i)[3]);
       //cout << "sx: " <<this->tabLayer->getButtonPosScale(i)[2]<<" sy: "<<this->tabLayer->getButtonPosScale(i)[3]<<endl;
       window->draw(sprite);

       sf::Font bfont;
       bfont.loadFromFile(this->tabLayer->getButtonFont());
       sf::Text btext(std::get<0>(this->tabLayer->getButton(i)),bfont,40);
       btext.move(x+15,y+15);
       window->draw(btext);
      }
    }
    window->draw(title);

}
void Scene::draw (sf::RenderWindow* window){

  while (window->isOpen())
 {

     updateScreen (window);


     // handle events
     sf::Event event;

     while (window->pollEvent(event))
     {
       if(event.type == sf::Event::Closed){
           window->close();
       } else {

           eventHandler(event);
       }

     }
     window->display();

 }
}

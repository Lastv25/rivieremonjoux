#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"


using namespace std;
using namespace render;
using namespace sf;

//Constructor
Scene::Scene (){
}

Scene::Scene (state::State* state,engine::Button* button){

  this->state = state;
  this->tabLayer = new ElementTabLayer(state->getGrid());
  this->buttonPressed = button;

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
void Scene::draw (sf::RenderWindow* window){
  sf::Sprite sprite;
  sf::Font font;
  sf::Text text;

  while (window->isOpen())
 {

   if (this->stateChangedBool){
     this->tabLayer->clearSurfaces();
     this->stateChangedBool = false;
     window->clear(sf::Color::Black);
   }


   this->tabLayer->getElementTabTextures();
   //cout << "state Title: " <<this->tabLayer->getTitle()<< ", taille surface list: " <<this->tabLayer->getSurfaceList().size()<< ", taille ButtonsSurface list: " <<this->tabLayer->getButtonsSurface().size()<<endl;

   font.loadFromFile("res/dc_o.ttf");
   sf::Text title(this->tabLayer->getTitle(),font,50);
   title.move(600.f,100.f);

   //cout << 1;

   if (this->tabLayer->getDrawSprite()){
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
      if (this->tabLayer->getText().find("None") == std::string::npos){
        text.setString(this->tabLayer->getText());
        text.setFont(font);
        text.setCharacterSize(35);
        text.move(this->tabLayer->getTextcoords()[0],this->tabLayer->getTextcoords()[1]);
        window->draw(text);
        //cout <<"x: "<<this->tabLayer->getTextcoords()[0]<< " y: "<<this->tabLayer->getTextcoords()[1]<<endl;
      }
    }
    //cout << 3;

    if (this->tabLayer->getButtonsSurface().size() != 0){
      for (uint i=0;i<this->tabLayer->getButtonsSurface().size();i++){
        sprite = this->tabLayer->getButtonSurface(i)->getSprite();
        float x =std::get<1>(this->tabLayer->getButton(i))[0];
        float y =std::get<1>(this->tabLayer->getButton(i))[1];
        sprite.setPosition(x,y);
        sprite.scale(this->tabLayer->getButtonPosScale(i)[2],this->tabLayer->getButtonPosScale(i)[3]);
        window->draw(sprite);

        sf::Font bfont;
        bfont.loadFromFile(this->tabLayer->getButtonFont());
        sf::Text btext(std::get<0>(this->tabLayer->getButton(i)),bfont,40);
        btext.move(x+15,y+15);
        window->draw(btext);
       }
     }
     //cout << 4;
     // handle events
     sf::Event event;
     while (window->pollEvent(event))
     {
         if(event.type == sf::Event::Closed){
             window->close();
         } else if (event.type == sf::Event::MouseButtonPressed){
           if(event.mouseButton.button == sf::Mouse::Left){
             for (uint i=0;i<this->tabLayer->getButtonsSurface().size();i++){
               //cout << this->tabLayer->getButtonsSurface().size() << endl;
               float x =std::get<1>(this->tabLayer->getButton(i))[0];
               float y =std::get<1>(this->tabLayer->getButton(i))[1];
               if (x < event.mouseButton.x && event.mouseButton.x < x+150 && y < event.mouseButton.y && event.mouseButton.y< y+50){
                 // cout << "mouse x: " <<event.mouseButton.x ;
                 // cout << "  mouse y: " <<event.mouseButton.y ;
                 // cout << " Button: " <<std::get<0>(this->tabLayer->getButton(i))<< endl;
                 this->buttonPressed->setCommand(std::get<0>(this->tabLayer->getButton(i)));
                 this->buttonPressed->setAdditionalParam(std::get<0>(this->tabLayer->getButton(i)));
                 this->buttonPressed->sendToEngine();
                 if (std::get<0>(this->tabLayer->getButton(i)).find("Attack")==std::string::npos or std::get<0>(this->tabLayer->getButton(i)).find("Next Turn")==std::string::npos){
                   this->stateChangedBool = true;
                   this->tabLayer->setSkillUsed(true);
                   this->tabLayer->setAlreadyDisplayedOnce("None");

                 }




                 //this->buttonPressed = std::get<0>(this->tabLayer->getButton(i));

              }
           }
         }
        }
     }

     //cout << 5 << endl;
     window->draw(title);

     window->display();

     // if (this->buttonPressed->getCommands().size() != 0){
     //   for (uint i=0; i<this->buttonPressed->getCommands().size();i++){cout<<"Command: " <<this->buttonPressed->getCommands()[i]<< " ";}
     //   cout << endl;
     // }



 }
}

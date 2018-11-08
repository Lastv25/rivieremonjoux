#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"


using namespace std;
using namespace render;
using namespace sf;

//Constructor
Scene::Scene (){
}

Scene::Scene (state::State* state){

  this->state = state;
  this->tabLayer = new ElementTabLayer(state->getGrid());

}
//Destructor
Scene::~Scene (){
}

//Operations
void Scene::stateChanged (state::State* state){
  this->state = state;
}

void Scene::draw (sf::RenderWindow* window){
  this->tabLayer->getElementTabTextures();
  sf::Sprite sprite;
  sf::Font font;
  font.loadFromFile("res/dc_o.ttf");
  sf::Text title(this->tabLayer->getTitle(),font,50);
  title.move(600.f,100.f);
  sf::Text text;
  if (this->tabLayer->getText().find("None") == std::string::npos){
    text.setString(this->tabLayer->getText());
    text.setFont(font);
    text.setCharacterSize(35);
    text.move(this->tabLayer->getTextcoords()[0],this->tabLayer->getTextcoords()[1]);
  }


  while (window->isOpen())
 {
     // handle events
     sf::Event event;
     while (window->pollEvent(event))
     {
         if(event.type == sf::Event::Closed)
             window->close();
     }


     window->clear(sf::Color::Black);
     if (this->tabLayer->getSurfaceList().size() != 1){
       for (uint i=0;i<this->tabLayer->getSurfaceList().size();i++){
          sprite = this->tabLayer->getSurface(i)->getSprite();
          sprite.setPosition(this->tabLayer->getCoords()[i][0],this->tabLayer->getCoords()[i][1]);
          sprite.scale(this->tabLayer->getCoords()[i][2],this->tabLayer->getCoords()[i][3]);
          window->draw(sprite);
        }
      } else {
        sprite = this->tabLayer->getSurface(0)->getSprite();
        sprite.setScale(1.15f,1.7f);
        window->draw(sprite);
      }
     window->draw(title);
     window->draw(text);
     window->display();
 }
}

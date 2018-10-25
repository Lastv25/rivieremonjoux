#include <iostream>
#include <SFML/Graphics.hpp>
#include "Layer.h"


using namespace std;
using namespace render;
using namespace sf;

//Constructor
Layer::Layer (){
}
//Destructor
Layer::~Layer (){
}
//Operationd
Surface* Layer::getSurface (int i){
  return this->surface[i];
}
void Layer::setSurface (Surface* surface){
  this->surface.push_back(surface);
}
void Layer::initSurface (){
}
void Layer::printText (){
}
std::vector<Surface*> Layer::getSurfaceList (){
  return this->surface;
}
const std::vector<std::pair<uint,uint>>& Layer::getCoords() const{
  return this->coords;
}
void Layer::setCoords(const std::vector<std::pair<uint,uint>>& coords){
  this->coords=coords;
}
void Layer::addCoords(std::pair<uint,uint> coords){
  this->coords.push_back(coords);
}

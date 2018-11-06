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
const std::vector<std::vector<float>>& Layer::getCoords() const{
  return this->coords;
}
void Layer::setCoords(const std::vector<std::vector<float>>& coords){
  this->coords=coords;
}
void Layer::addCoords(std::vector<float> coords){
  this->coords.push_back(coords);
}
const std::vector<float>& Layer::getTextcoords() const{
  return this->textcoords;
}
void Layer::setTextcoords(const std::vector<float>& textcoords){
  this->textcoords = textcoords;
}

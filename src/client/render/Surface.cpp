#include "Surface.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace render;
using namespace sf;

//Constructor
Surface::Surface (uint width,uint height,uint wSize, uint hSize){
  this->width=width;
  this->height=height;
  this->wSize=wSize;
  this->hSize=hSize;
}
//Destructor
Surface::~Surface (){
}

//Setters and Getters
sf::Texture Surface::getTexture (){
  return this->texture;
}
void Surface::setTexture (sf::Texture newTexture){
  this->texture=newTexture;
}
sf::VertexArray Surface::getQuads (){
  return this->quads;
}
void Surface::setQuads (sf::VertexArray newQuad){
  this->quads=newQuad;
}

//Operations
void Surface::loadTexture (std::string image_txt) {
  sf::Texture newtext;
  if (!newtext.loadFromFile(image_txt)){
      cout << "This texture does not exist" << endl;
  } else {
      this->setTexture(newtext);
  }
}

void Surface::initQuads (int count){
  this->quads.setPrimitiveType(sf::Quads);
  this->quads.resize(this->width * this->height * 4);
}
void Surface::setSprite (){
  sf::Sprite sp;
  sp.setTexture(this->texture);
  this->sprite=sp;
}
void Surface::spriteSetScale (float x,float y){
  sf::Sprite sp=this->sprite;
  sp.setScale(x,y);
  this->sprite=sp;
}

sf::Sprite Surface::getSprite (){
  return this->sprite;
}
void Surface::setSpriteLocation (int x, int y, int i){
  //resize the vertex array to fit the level size
          this->quads.setPrimitiveType(sf::Quads);
          this->quads.resize(width * height * 4);
          quads[0].position = sf::Vector2f(0,0);
          quads[1].position = sf::Vector2f(0,width);
          quads[2].position = sf::Vector2f(height,width);
          quads[3].position = sf::Vector2f(height,0);
          // // populate the vertex array, with one quad per tile
          // for (unsigned int i = 0; i < width; ++i)
          //     for (unsigned int j = 0; j < height; ++j)
          //     {
          //         // get the current tile number
          //         int tileNumber = tiles[i + j * width];
          //
          //         // find its position in the tileset texture
          //         int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
          //         int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
          //
          //         // get a pointer to the current tile's quad
          //         sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
          //
          //         // define its 4 corners
          //         quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
          //         quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
          //         quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
          //         quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
          //       }
          //   }
}
//
void Surface::setSpriteTexture (int i){
  this->quads.setPrimitiveType(sf::Quads);
  this->quads.resize(width * height * 4);
  quads[0].position = sf::Vector2f(0,0);
  quads[1].position = sf::Vector2f(0,width);
  quads[2].position = sf::Vector2f(height,width);
  quads[3].position = sf::Vector2f(height,0);
  // populate the vertex array, with one quad per tile
  // for (unsigned int i = 0; i < width; ++i)
  //     for (unsigned int j = 0; j < height; ++j)
  //     {
  //         // get the current tile number
  //         int tileNumber = tiles[i + j * width];
  //
  //         // find its position in the tileset texture
  //         int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
  //         int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
  //
  //         // get a pointer to the current tile's quad
  //         sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
  //         // define its 4 texture coordinates
  //         quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
  //         quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
  //         quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
  //         quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
  //       }
  //   }
}



void  Surface::draw (sf::RenderTarget& target, sf::RenderStates states) const{
  states.transform *= getTransform();
  states.texture = &texture;
  target.draw(quads,states);
}

void Surface::setFont(sf::Font font){
  this->font=font;
}

#include "RegisterPlayerCommand.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <json/json.h>

using namespace std;
using namespace sf;
using namespace engine;


RegisterPlayerCommand::RegisterPlayerCommand ():Command(){
  this->commandTypeId = RegisterPlayer;
}
RegisterPlayerCommand::~RegisterPlayerCommand (){
}
CommandTypeId RegisterPlayerCommand::getCommandTypeId (){
  return this->commandTypeId;
}
//Network put request
int RegisterPlayerCommand::putNewPlayer(){
  sf::Http http("http://localhost",8080);
  //Post request to register new player
  Json::Value player;
  player["name"]="player";
  sf::Http::Request req ("/user",sf::Http::Request::Post);
  req.setBody(player.toStyledString());
  sf::Http::Response response = http.sendRequest(req);

  if (response.getStatus()==sf::Http::Response::Created){
    //cout<< response.getBody()<<endl;
    //Get This player Id
    Json::Value root;
    Json::Value players;
    Json::Reader reader;
    if (!reader.parse(response.getBody(),root,false)){cout <<reader.getFormattedErrorMessages()<<endl;}
    int id=root["id"].asInt();
    if (id==-1){
      cout << "No more connections possible"<<endl;
      return -1;
    } else {
      return id;
    }
  } else {
    cout << "Post Request Failed: "<<response.getStatus()<<endl;
    return -1;
  }
}


void RegisterPlayerCommand::execute (state::State* state){
  //Adding new Player
  int id =putNewPlayer();

}
void RegisterPlayerCommand::executeInv (state::State* state){
}

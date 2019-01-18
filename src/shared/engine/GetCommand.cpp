#include "GetCommand.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <json/json.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace sf;
using namespace engine;
using namespace std::chrono;
using namespace std::this_thread;

//Network Get request
// int GetCommand::getPlayerList(){
//   // sf::Http http("http://localhost",8080);
//   // sf::Http::Response response;
//   // sf::Http::Request req ("/user",sf::Http::Request::Get);
//   // response = http.sendRequest(req);
//   //
//   // if (response.getStatus()==sf::Http::Response::Ok){
//   //   cout<< response.getBody()<<endl;
//   //   Json::Value root;
//   //   Json::Reader reader;
//   //   if (!reader.parse(response.getBody(),root,false)){cout <<reader.getFormattedErrorMessages()<<endl;}
//   //   return root["Players"].size();
//   // } else {
//   //   cout << "Get Request Failed: "<<response.getStatus()<<endl;
//   //   return -1;
//   // }
// }


GetCommand::GetCommand ():Command(){
  this->commandTypeId = CheckPlayers;
}
GetCommand::~GetCommand (){
}
CommandTypeId GetCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void GetCommand::execute (state::State* state){
  // int playersNumber = getPlayerList();
  // state->setPlayerConnected(playersNumber);
  // cout <<playersNumber<<endl;
}
void GetCommand::executeInv (state::State* state){
}

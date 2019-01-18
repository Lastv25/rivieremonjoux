#include "SendCommand.h"
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
// int SendCommand::getPlayerList(){
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


SendCommand::SendCommand ():Command(){
  this->commandTypeId = CheckPlayers;
}
SendCommand::~SendCommand (){
}
CommandTypeId SendCommand::getCommandTypeId (){
  return this->commandTypeId;
}
void SendCommand::execute (state::State* state){
  // int playersNumber = getPlayerList();
  // state->setPlayerConnected(playersNumber);
  // cout <<playersNumber<<endl;
}
void SendCommand::executeInv (state::State* state){
}

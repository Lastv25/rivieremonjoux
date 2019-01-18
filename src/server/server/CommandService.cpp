/**
 * @file CommandService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "CommandService.hpp"
#include <string.h>

using namespace std;
using namespace server;

CommandService::CommandService () : AbstractService("/command"){
}
//Setters and Getters
const std::map<int,Command*>& CommandService::getCommandMap() const{
  return this->commandMap;
}
void CommandService::setCommandMap(const std::map<int,Command*>& commandMap){
  this->commandMap=commandMap;
}
//Operations
HttpStatus CommandService::get (Json::Value& out, int id) const {
    std::map<int,Command*> map = getCommandMap();
    if (map.find(id)==map.end()){
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id");
    }
    out["id"] = map[id]->id;
    out["param1"] = map[id]->param1;
    out["param2"] = map[id]->param2;
    return HttpStatus::OK;
}

HttpStatus CommandService::getAll (Json::Value& out) const {
    out["Commands"]=Json::arrayValue;
    std::map<int,Command*> map = getCommandMap();
    if (map.size()==0){
      throw ServiceException(HttpStatus::NOT_FOUND,"No Commands registered");
    }
    Json::Value intermediaryJson;
    for (uint i=0;i<map.size();i++){
      intermediaryJson["id"] = map[i]->id;
      intermediaryJson["param1"] = map[i]->param1;
      intermediaryJson["param2"] = map[i]->param2;
      out["Commands"].append(intermediaryJson);
    }
    return HttpStatus::OK;
}

HttpStatus CommandService::post (const Json::Value& in, int id) {
    std::map<int,Command*> map = getCommandMap();
    if (map.find(id)==map.end()){
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id");
    }
    Command* c =new Command(in["id"].asInt(),in["param1"].asString(),in["param2"].asString());
    map[id]=c;
    return HttpStatus::NO_CONTENT;
}

HttpStatus CommandService::put (Json::Value out, const Json::Value& in) {
    std::map<int,Command*> map = getCommandMap();
    Command* c =new Command(in["id"].asInt(),in["param1"].asString(),in["param2"].asString());
    map[map.size()]=c;
    return HttpStatus::CREATED;
}

HttpStatus CommandService::remove (int id) {
    std::map<int,Command*> map = getCommandMap();
    if (map.find(id)==map.end()){
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id");
    }
    auto it = map.find(id);
    map.erase(it);
    return HttpStatus::NO_CONTENT;
}

/**
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"
#include <string.h>

using namespace std;
using namespace server;

UserService::UserService (UserDB& userDB) : AbstractService("/user"),
    userDB(userDB) {

}

HttpStatus UserService::get (Json::Value& out, int id) const {
    const User* user = userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    out["name"] = user->name;
    out["Id"] = user->playerId;
    return HttpStatus::OK;
}

HttpStatus UserService::getAll (Json::Value& out) const {
    out["Players"]=Json::arrayValue;
    const std::vector<User*> users = userDB.getAllUser();
    if (users.size()==0){
      throw ServiceException(HttpStatus::NOT_FOUND,"No Users registered");
    }
    Json::Value intermediaryJson;
    for (uint i=0;i<users.size();i++){
      intermediaryJson["name"]=users[i]->name;
      intermediaryJson["Id"]=users[i]->playerId;
      out["Players"].append(intermediaryJson);
    }
    return HttpStatus::OK;
}

HttpStatus UserService::post (const Json::Value& in, int id) {
    const User* user = userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    unique_ptr<User> usermod (new User(*user));
    if (in.isMember("name")) {
        usermod->name = in["name"].asString();
    }
    userDB.setUser(id,std::move(usermod));
    return HttpStatus::NO_CONTENT;
}

HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
    string name = in["name"].asString();
    out["id"] = userDB.addUser(make_unique<User>(name));
    return HttpStatus::CREATED;
}

HttpStatus UserService::remove (int id) {
    const User* user = userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    userDB.removeUser(id);
    return HttpStatus::NO_CONTENT;
}

/**
 * @file ServicesManager.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "ServicesManager.hpp"
#include <string.h>

using namespace std;
using namespace server;

void ServicesManager::registerService (unique_ptr<AbstractService> service) {
    services.push_back(std::move(service));
}

AbstractService* ServicesManager::findService (const std::string& url) const {
    for (auto& service : services) {
        const std::string& pattern(service->getPattern());
        if (url.find(pattern) != 0)
            continue;
        if (url.size() > pattern.size() && url[pattern.size()] != '/')
            continue;
        return service.get();
    }
    return nullptr;
}

HttpStatus ServicesManager::queryService (std::string& out, const std::string& in, const std::string& url, const std::string& method) {
    bool userNOid=false;
    AbstractService* service = findService(url);
    if (!service)
        throw ServiceException(HttpStatus::NOT_FOUND,"Service "+url+" non trouvé");
    // Recherche un éventuel id (ex: /mon/service/<id>)
    const std::string& pattern(service->getPattern());
    int id = 0;
    if (pattern.find("user")!=std::string::npos || pattern.find("command")!=std::string::npos){
      if (url.size() > pattern.size()+1) {
        std::string end = url.substr(pattern.size()+1);
        if (end.empty())
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
        try {
            size_t pos = 0;
            id = stoi(end,&pos);
            if (pos != end.size())
                throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
        catch(...) {
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
      } else {
        userNOid=true;
      }
    } else{
      cout << "Pattern user not used"<<endl;
      //throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre> ou <service>/)");
    }

    // Traite les différentes méthodes
    if (method == "GET") {
        cerr << "Requête GET " << pattern << " avec id=" << id << endl;
        Json::Value jsonOut;
        HttpStatus status;
        if (userNOid){
          status = service->getAll(jsonOut);
        } else {
          status = service->get(jsonOut,id);
        }
        out = jsonOut.toStyledString();
        return status;
    }
    else if (method == "POST") {
        cerr << "Requête POST " << pattern << " avec contenu: " << in << endl;
        if (userNOid){
          Json::Reader jsonReader;
          Json::Value jsonIn;
          if (!jsonReader.parse(in,jsonIn))
              throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
          Json::Value jsonOut;
          HttpStatus status = service->put(jsonOut,jsonIn);
          out = jsonOut.toStyledString();
          return status;
        } else {
          Json::Reader jsonReader;
          Json::Value jsonIn;
          if (!jsonReader.parse(in,jsonIn))
              throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
          return service->post(jsonIn,id);
        }
    }
    else if (method == "PUT") {
        cerr << "Requête PUT " << pattern << " avec contenu: " << in << endl;
        Json::Reader jsonReader;
        Json::Value jsonIn;
        if (!jsonReader.parse(in,jsonIn))
            throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
        Json::Value jsonOut;
        HttpStatus status = service->put(jsonOut,jsonIn);
        out = jsonOut.toStyledString();
        return status;
    }
    else if (method == "DELETE") {
        cerr << "Requête DELETE" << endl;
        return service->remove(id);
    }
    throw ServiceException(HttpStatus::BAD_REQUEST,"Méthode "+method+" invalide");
}

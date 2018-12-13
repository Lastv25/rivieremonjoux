#include "Noeud.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace ai;


Noeud::Noeud(std::pair<state::Team*,int> data){
  //COnstructeur de la tete de l'arbre
  this->parent=nullptr;
  this->etage =0;
  this->istete=true;
  this->data=data;
  std::vector<Noeud*> children ={};
  this->children=children;
}

Noeud::Noeud(std::pair<state::Team*,int> data, int etage,Noeud* parent, Noeud* tete){
  Noeud* precedent = nullptr;
  Noeud* courant = tete;
  int comptEtage =0;
  std::pair<Noeud*,int> parentLoc;
  parentLoc = rechercheloc_ite(parent,tete);
  if (etage==0){
    this->istete=true;
  }
  else{
    this->istete=false;
  }

  precedent=parentLoc.first;
  // je regarde les enfants du grand-pere pour trouver mon pere
  for (int i=0;i<precedent->children.size();i++){
    if(precedent->children[i]==parent){
      courant=precedent->children[i];
      //il faut trouver à caster les * en share_ptr pour l'attribution
    }
  }
  comptEtage=parentLoc.second +1;
  //nous sommes à la bonne localisation : il faut attribuer les attributs de notre nouveau Noeud
  this->etage=comptEtage;
  this->parent=courant;
  this->data=data;
  std::vector<Noeud*> children ={};
  //Ne pas oublier de push back les infos dans le père de notre element qui se fait dans une méthode
  // inserer : precedent = parent et courant va dans les enfants du parent
  //this->parent->children.push_back(data);
}

Noeud::~Noeud(){
 //destructeur
}

std::vector<Noeud*> Noeud::getChildren (){
 return this->children;
}
int Noeud::getEtage (){
 return this->etage;
}
std::pair<state::Team*,int> Noeud::getData (){
 return this->data;
}
bool Noeud::getIsTete (){
 return this->istete;
}
Noeud* Noeud::getParent (){
 return this->parent;
}

std::pair<state::Team*,int> Noeud::recherchedata_ite(Noeud* noeud, Noeud* tete){
  // std::vector<Noeud*> chemin ={};
  // Noeud* courant= noeud->parent;
  // while(courant->parent != tete){
  //   chemin.push_back(courant);
  //   courant=courant->parent;
  // }
  // besoin de faire tout ça ?
  // si oui faire des for pour trouver des proches en proches le fils du chemin qui correspon au
  // cast : et ensuite extraire data

  return noeud->data;






  // int i= Noeud->etage;
  // //On regard l'étage au dessus du noeud (l'étage du père), et on regarde si on trouve le même père
  // if((i==this->etage-1) && (noeud->parent == this)){
  //   //On parcoure les enfants du père commun
  //   for (int j=0;j<this->children.size(),j++){
  //     //On choisit l'enfant qui correspond
  //     if(this->children[j]->data==noeud->data){
  //       return data;
  //     }
  //   }
  // }
  // else if (this->children->children.size()!=0){
  //   this->etage++;
  //   recherchedata_rec(noeud);
  // }
  // else {}
 // cherche l'information contenue dans le noeud pour checker les score
}

std::pair<Noeud*,int> Noeud::rechercheloc_ite(Noeud* noeud, Noeud* tete){
 //renvoie le père ainsi que son étage pour la création de son enfant
}

void Noeud::inserer(Noeud* noeud){
  noeud->parent->children.push_back(noeud);
}
//pseudo code pour inserer
//chercher le pere par rechercheloc_rec (qui renvoie juste un noeud)
// pere->enfant.push_back noeud

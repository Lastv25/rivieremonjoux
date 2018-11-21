#include "Skills.h"
#include <vector>
#include <iostream>
#include <random>
using namespace state ;
using namespace std;

// Constructeurs

Skills::Skills(){
}

Skills::Skills (Character* chara1, Character* chara2){
    this->userCharacter = chara1;
    this->receiverCharacter = chara2;
    this->skillList = chara1->getSkillList();
}

// Destructeur
Skills::~Skills (){
}
//Setters and Getters
Character* Skills::getUser (){
  return this->userCharacter;
}
Character* Skills::getReceiver (){
  return this->receiverCharacter;
}
void Skills::setUser (Character* newUser){
  this->userCharacter=newUser;
}
void Skills::setReceiver (Character* newReceiver){
  this->receiverCharacter=newReceiver;
}
std::vector<std::string> Skills::getSkilList (){
  return this->skillList;
}
void Skills::setSkillList (std::vector<std::string> newSkillList){
  this->skillList=newSkillList;
}

//Operations
void Skills::addSkill (std::string skillName){
  this->skillList.push_back(skillName);
}
void Skills::UseSkill (std::string skillName, Character* user, Character* receiver){
  if (skillName.find("HeavyAttack")!=std::string::npos){
    HeavyAttack(user,receiver);
  } else if (skillName.find("Poison")!=std::string::npos){
    Poison(user,receiver);
  } else if (skillName.find("Heal")!=std::string::npos){
    Heal(user,receiver);
  } else{
    Attack(user,receiver);
  }
}
bool Skills::isCrit(){
  return rand()/(RAND_MAX +1.0)< this->userCharacter->getCrit()/100;
}
void Skills::Attack (Character* user, Character* receiver){
  int attValue = user->getATT();
  int defValue = receiver->getDEF();
  int currentLife = receiver->getLife();

  if (isCrit()){
    cout << "Critical Hit to " <<receiver->getName()<<": " ;
    cout << attValue*2-defValue << endl;
    receiver->setLife(attValue*2-defValue);
  } else {
    cout << "Damages to " <<receiver->getName()<<": " ;
    cout << attValue-defValue << endl;
    receiver->setLife(currentLife-(attValue-defValue));
  }

}

void Skills::HeavyAttack (Character* user, Character* receiver){
  int attValue = 1.5*user->getATT();
  int skillp = user->getSkillpoints();
  int defValue = receiver->getDEF();
  int currentLife = receiver->getLife();

  if (skillp-3 >= 0){
    user->setSkillpoints(skillp-3);
    if (isCrit()){
      cout << "Critical Hit to " <<receiver->getName()<<": " ;
      cout << attValue*2-defValue << endl;
      receiver->setLife(attValue*2-defValue);
    } else {
      cout << "Damages to " <<receiver->getName()<<": " ;
      cout << attValue-defValue << endl;
      receiver->setLife(currentLife-(attValue-defValue));
    }
  } else{
    cout << "You do not have enouth skillpoints left" <<endl;
  }
}

void Skills::Poison (Character* user, Character* receiver){
  int attValue = 0.5*user->getATT();
  int skillp = user->getSkillpoints();
  int defValue = receiver->getDEF();
  int currentLife = receiver->getLife();

  if (skillp-5 >= 0){
    user->setSkillpoints(skillp-5);
    receiver->setTurnEffect(3);
    if (isCrit()){
      cout << "Critical Hit to " <<receiver->getName()<<": " ;
      cout << attValue*2-defValue << endl;
      receiver->setLife(attValue*2-defValue);
      receiver->changeState(1);
    } else {
      cout << "Damages to " <<receiver->getName()<<": " ;
      cout << attValue-defValue << endl;
      receiver->setLife(currentLife-(attValue-defValue));
      receiver->changeState(1);
    }
  } else{
    cout << "You do not have enouth skillpoints left" <<endl;
  }
}
void Skills::Heal (Character* user, Character* receiver){
  int currentLife = receiver->getLife();

  cout << "Heal to " <<receiver->getName()<<": " ;
  cout << 5 << endl;
  receiver->setLife(currentLife+5);


}

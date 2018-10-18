#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "string.h"

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

using namespace std;
using namespace state;

void affichagebeauTest(std::string testname){
  for (int comt=0;comt<50;comt++){
           cout << '_';
  }
  cout << endl;
  for (int comt=0;comt<20;comt++){
  cout << ' ';}
  cout  << "Test " <<testname<< endl;
}

int main(int argc,char* argv[])
{


    //printf("%s\n", argv[1]);
    //printf("%d\n", argc);


    if (argc == 2) {
      if ( !strcmp(argv[1],"hello") ){
        cout << "Bonjour le monde!" << endl;
      } else if (!strcmp(argv[1],"state") ) {
        cout << "Test des différents états" << endl;


         {
           affichagebeauTest("MobileElements");
           MobileElements* e = new MobileElements(true);
           cout <<"is Character:"<< e->isCharacter() << endl;
           cout << "is Static"<<e->isStatic() << endl;
         };
         {
           affichagebeauTest("Character");
           Character* e = new Character(5,2,3,4,5,"test");
           cout <<  " is Character: "<<e->isCharacter() <<endl;
           cout << " is Static: " << e->isStatic()<< endl;
           cout << " life: " << e->getLife()<<endl;
           cout << " life Max: " << e->getLifeMAX()<<endl;
           cout << " att: " << e->getATT()<<endl;
           cout << " def: " << e->getDEF()<< endl;
           cout <<  " spd: "<< e->getSPD()<<endl;
           cout <<  " crit: "<< e->getCrit()<<endl;
           cout <<  " State: "<< e->getState()[0]<<endl;
           cout <<" "<<endl;
           cout <<"Change state to normal"<<endl;
           e->changeState(0);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to 5"<<endl;
           e->changeState(5);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned and staggered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to normal"<<endl;
           e->changeState(0);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to stagered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned and staggered"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to stagered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to dead"<<endl;
           e->changeState(3);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to dead"<<endl;
           e->changeState(3);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to stagered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to normal"<<endl;
           e->changeState(0);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<" "<<endl;
           cout <<"Change life to -10"<<endl;
           e->setLife(-10);
           cout << "New Life "<<e->getLife() <<endl;
           cout <<"Change life to 10"<<endl;
           e->setLife(10);
           cout << "New Life "<<e->getLife() <<endl;
         };
         {
           affichagebeauTest("Hero");
           Hero* e = new Hero;
           cout << " is monster?" << e->isMonster() <<endl;
           affichagebeauTest("Monsters");
           Monsters* m = new Monsters;
           cout <<  " is monster?" <<m->isMonster() <<endl;
         };
         {
           affichagebeauTest("Tank (une des unitées)");
           Tank* e = new Tank(1,2,3,4,5,"Hadrien");
           cout << " is Character: " <<e->isCharacter() << endl;
           cout << " is Static: "<< e->isStatic() << endl;
           cout <<  " life: "<<e->getLife() <<endl;
           cout << " life Max: "<< e->getLifeMAX()<<endl;
           cout << " att: "<< e->getATT() <<endl;
           cout<< " def: "<<  e->getDEF() << endl;
           cout << " spd: "<< e->getSPD() <<endl;
           cout  << " crit: "<< e->getCrit()<<endl;
           cout  << " State: "<< e->getState()[0]<<endl;
           cout << " Name: "<< e->getName() <<endl;
         };
         {
           affichagebeauTest("Team");
           Tank* e1 = new Tank(1,2,3,4,5,"Hadrien1");
           Tank* e2 = new Tank(1,2,3,4,5,"Hadrien2");
           Tank* e3 = new Tank(1,2,3,4,5,"Hadrien3");
           Tank* e4 = new Tank(1,2,3,4,5,"Hadrien4");
           cout <<"Team creation (of Tanks)"<<endl;
           Team* t=new Team();
           t->addToTeam(e1);
           t->addToTeam(e2);
           t->addToTeam(e3);
           t->addToTeam(e4);
           for (uint i =0;i<t->getTeam().size();i++){Character* intermediary =t->getTeam()[i];cout<<"Tank name "<<intermediary->getName()<<endl;};
           cout <<"removing an element of Team"<<endl;
           t->removeFromTeam(e3);
           for (uint i =0;i<t->getTeam().size();i++){cout<<"Tank name "<<t->getTeam()[i]->getName()<<endl;};
           cout <<"is monster team? "<< t-> isHeroTeam() <<endl;
         };
         {
           affichagebeauTest("StaticElements");
           StaticElements* s = new StaticElements(true);
           cout << "is Building: "<<s->isBuilding() << endl;
           cout << "is Static: "<<s->isStatic() << endl;
         };
         {
           affichagebeauTest("Items");
           Item* s = new Item("potion");
           cout << "is Building: "<<s->isBuilding() << endl;
           cout << "is Static: "<<s->isStatic() << endl;
           cout << "Item Name: "<<s ->getName() << endl;
         };
         {
           affichagebeauTest("Inventory");
           Item* s1 = new Item("potion1");
           Item* s2 = new Item("potion2");
           Item* s3 = new Item("potion3");
           Inventory* i= new Inventory(2);
           cout << "Test adding to inventory" << endl;
           i->addItem(s1->getName());
           i->addItem(s2->getName());
           i->addItem(s1->getName());
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
           }
           cout << "Test adding too much to inventory" << endl;
           i->addItem(s3->getName());
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
           }
           cout << "Test clearing from inventory" << endl;
           i->clearItem("potion1");
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
           }
           cout << "Test removing too much from inventory" << endl;
           i->removeItem("potion1",3);
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
            }
          };
          {
            affichagebeauTest("Tavern (has a team of max 1 member)");
            Blob* b = new Blob(1,2,3,4,5,"Hadrien");
            Team* t=new Team();
            t->addToTeam(b);
            Tavern* ta = new Tavern(t,1);
            cout << "Adding one character to the team and testing if the team in the tavern is full"<<endl;
            ta->isTeamFull();
            cout << "Getting stats of team member"<<endl;
            ta->getStat(b);
           };
        }
      } else {
        cout << "Veuillez tapez hello s'il vous plait." << endl;
      }

    return 0;
}

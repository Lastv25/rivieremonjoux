#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include "string.h"
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#define quote(x) #x

using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;
using namespace sf;

void renderWindow(ElementTabLayer* layer) {

    sf::RenderWindow window(sf::VideoMode(1440,1160), "Darkest Dungeon Like");

    sf::Sprite sprite;
    sf::Font font;
    font.loadFromFile("res/dc_o.ttf");
    sf::Text title(layer->getTitle(),font,50);
    title.move(600.f,100.f);
    sf::Text text;
    if (layer->getText().find("None") == std::string::npos){
      text.setString(layer->getText());
      text.setFont(font);
      text.setCharacterSize(35);
      text.move(layer->getTextcoords()[0],layer->getTextcoords()[1]);
    }


    while (window.isOpen())
   {
       // handle events
       sf::Event event;
       while (window.pollEvent(event))
       {
           if(event.type == sf::Event::Closed)
               window.close();
       }


       window.clear(sf::Color::Black);
       if (layer->getSurfaceList().size() != 1){
         for (uint i=0;i<layer->getSurfaceList().size();i++){
            sprite = layer->getSurface(i)->getSprite();
            sprite.setPosition(layer->getCoords()[i][0],layer->getCoords()[i][1]);
            sprite.scale(layer->getCoords()[i][2],layer->getCoords()[i][3]);
            window.draw(sprite);
          }
        } else {
          sprite = layer->getSurface(0)->getSprite();
          sprite.setScale(1.15f,1.7f);
          window.draw(sprite);
        }
       window.draw(title);
       window.draw(text);
       window.display();
   }

}

std::string elementClassNameToString(const char* name){
    std::string intemediary(name);
    return intemediary;
  }



void affichagebeauTest(std::string testname){
  for (int comt=0;comt<50;comt++){
           cout << '_';
  }
  cout << endl;
  for (int comt=0;comt<20;comt++){
  cout << ' ';}
  cout  << "Test " <<testname<< endl;
}
void affichagebeauVect(std::vector<std::string> vect){
  if (vect.size()!= 0){
    for (uint i=0;i<vect.size();i++){
        cout << vect[i] <<endl;
    }
  } else {
        cout << "Empty " <<endl;
  }
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
           affichagebeauTest("Dungeon");
           Team* t=new Team();
           std::vector<std::string> maplist;
           maplist.push_back("Map1");
           maplist.push_back("Map2");
           Dungeon* d = new Dungeon(maplist,t);
           for (uint i =0;i<d->getMapNames().size();i++){cout<<"Map name "<<d->getMapNames()[i]<<endl;};
         };
         {
           affichagebeauTest("Room");
           Tank* e1 = new Tank(1,2,3,4,5,"Hadrien1");
           Tank* e2 = new Tank(1,2,3,4,5,"Hadrien2");
           Blob* b3 = new Blob(1,2,3,4,5,"Hadrien3");
           cout <<"Teams creations"<<endl;
           Team* t1=new Team();
           t1->addToTeam(e1);
           t1->addToTeam(e2);
           Team* t2=new Team();
           t1->addToTeam(b3);
           Room* r = new Room(t1,t2,false,0);
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

      } else if (!strcmp(argv[1],"render") ) {
          affichagebeauTest("render");
          {

          ElementTab* e =new ElementTab();
          Team* t1=new Team();
          Team* t2=new Team();
          Sorcerer* sorcerer = new Sorcerer(10,20,3,40,5,"Sorcerer");
          Tank* tank = new Tank(10,20,3,40,5,"Tank");
          Blob* blob = new Blob(10,20,3,40,5,"Blob");
          Range* range = new Range(10,20,3,40,5,"Range");
          Assassin* assassin = new Assassin(10,20,3,40,5,"Assassin");
          DarkKnight* darkKnight = new DarkKnight(10,20,3,40,5,"DarkKnight");
          t1->addToTeam(sorcerer);
          t2->addToTeam(tank);
          t1->addToTeam(blob);
          t2->addToTeam(range);
          t2->addToTeam(assassin);
          t1->addToTeam(darkKnight);
          Tavern* tav= new Tavern(t2,1);
          Inventory* inv= new Inventory();
          std::map<std::string,int> shopinventory;
          Shop* shop= new Shop(inv,shopinventory,12);
          std::vector<std::string> dList;
          dList.push_back("EngineTest");
          //Village* r = new Village(tav,shop,3,inv,t1); //Decomenter pour Obtenir l'affichage de l'etat village
          //Dungeon* r = new Dungeon(dList);
          // Room* r = new Room(t2,t1,0,1); //Decomenter pour Obtenir l'affichage de l'etat Room
          //Tavern* r = new Tavern(); //Decomenter pour Obtenir l'affichage de l'etat Room
          e->add(tav,elementClassNameToString(typeid(tav).name()));
          ElementTabLayer* E =new ElementTabLayer(e);
          E->getElementTabTextures();
          renderWindow(E);
          };
      } else if (!strcmp(argv[1],"engine") ) {
          affichagebeauTest("engine");
          Observer* o = new Observer();
          State* s = new State();
          Engine* e = new Engine(s);
          RandomAI* rai = new RandomAI(e,s);
          Button* button = new Button(e);
          Scene* scene = new Scene(s,button,rai);
          s->registerObserver(o);

          sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1440,1160), "Darkest Dungeon Like");

          cout << "Creation of the Village" << endl;
          e->addCommand(3);
          e->update();
          cout << "Team composed of a Tank, a Range and an Assassin" << endl;
          Team* team = new Team();
          Village* v= (Village*) s->getGrid()->get(0,0);
          Tank* tank = new Tank(10,20,3,40,5,"Tank");
          Range* range = new Range(10,20,3,40,5,"Range");
          Assassin* assassin = new Assassin(10,20,3,40,5,"Assassin");
          team->addToTeam(tank);
          team->addToTeam(range);
          team->addToTeam(assassin);
          v->setTeam(team);
          s->getGrid()->replaceElement(v,"Village",0);

          scene->draw(window);




      } else if (!strcmp(argv[1],"random_ai") ) {
        affichagebeauTest("random_AI");
            Observer* o = new Observer();
            State* s = new State();
            Engine* e = new Engine(s);
            Button* button = new Button(e);
            RandomAI* rai = new RandomAI(e,s);
            Scene* scene = new Scene(s,button,rai);
            s->registerObserver(o);
            sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1440,1160), "Darkest Dungeon Like");
            e->addCommand(3);
            e->update();
            Team* team = new Team();
            Village* v= (Village*) s->getGrid()->get(0,0);
            Tank* tank = new Tank(10,20,3,40,5,"Tank");
            Range* range = new Range(10,20,3,40,5,"Range");
            Assassin* assassin = new Assassin(10,20,3,40,5,"Assassin");
            team->addToTeam(tank);
            team->addToTeam(range);
            team->addToTeam(assassin);
            v->setTeam(team);
            s->getGrid()->replaceElement(v,"Village",0);
            e->addCommand(1);
            e->update();
            e->setAdditionalParameters("EngineTest");
            e->addCommand(7);
            e->addCommand(2);
            e->update();
            scene->draw(window);

      } else if (!strcmp(argv[1],"heuristic_ai") ) {
        affichagebeauTest("heuristic_AI");
            Observer* o = new Observer();
            State* s = new State();
            Engine* e = new Engine(s);
            Button* button = new Button(e);
            HeuristicAI* hai = new HeuristicAI(s);
            Scene* scene = new Scene(s,button,hai);
            s->registerObserver(o);
            sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1440,1160), "Darkest Dungeon Like");
            e->addCommand(3);
            e->update();
            Team* team = new Team();
            Village* v= (Village*) s->getGrid()->get(0,0);
            Tank* tank = new Tank(10,20,3,40,5,"Tank");
            Range* range = new Range(10,20,3,40,5,"Range");
            Assassin* assassin = new Assassin(10,20,3,40,5,"Assassin");
            team->addToTeam(tank);
            team->addToTeam(range);
            team->addToTeam(assassin);
            v->setTeam(team);
            s->getGrid()->replaceElement(v,"Village",0);
            e->addCommand(1);
            e->update();
            e->setAdditionalParameters("EngineTest");
            e->addCommand(7);
            e->addCommand(2);
            e->update();
            scene->draw(window);

      } else if (!strcmp(argv[1],"rollback") ) {
            affichagebeauTest("rollback");
            Observer* o = new Observer();
            State* s = new State();
            Engine* e = new Engine(s);
            e->setRollback(true);
            Button* button = new Button(e);
            HeuristicAI* hai = new HeuristicAI(s);
            Scene* scene = new Scene(s,button,hai);
            s->registerObserver(o);
            sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1440,1160), "Darkest Dungeon Like");
            e->addCommand(3);
            e->update();
            Team* team = new Team();
            Village* v= (Village*) s->getGrid()->get(0,0);
            Tank* tank = new Tank(10,20,3,40,5,"Tank");
            Range* range = new Range(10,20,3,40,5,"Range");
            Assassin* assassin = new Assassin(10,20,3,40,5,"Assassin");
            team->addToTeam(tank);
            team->addToTeam(range);
            team->addToTeam(assassin);
            v->setTeam(team);
            s->getGrid()->replaceElement(v,"Village",0);
            e->addCommand(1);
            e->update();
            e->setAdditionalParameters("EngineTest");
            e->addCommand(7);
            e->addCommand(2);
            e->update();
            scene->draw(window);

      } else if (!strcmp(argv[1],"deep_ai") ) {
            affichagebeauTest("rollback");
            Observer* o = new Observer();
            State* s = new State();
            Engine* e = new Engine(s);
            Button* button = new Button(e);
            DeepAI* hai = new DeepAI(s);
            Scene* scene = new Scene(s,button,hai);
            s->registerObserver(o);
            sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1440,1160), "Darkest Dungeon Like");
            e->addCommand(3);
            e->update();
            Team* team = new Team();
            Village* v= (Village*) s->getGrid()->get(0,0);
            Tank* tank = new Tank(10,20,3,40,5,"Tank");
            Range* range = new Range(10,20,3,40,5,"Range");
            Assassin* assassin = new Assassin(10,20,3,40,5,"Assassin");
            team->addToTeam(tank);
            team->addToTeam(range);
            team->addToTeam(assassin);
            v->setTeam(team);
            s->getGrid()->replaceElement(v,"Village",0);
            e->addCommand(1);
            e->update();
            e->setAdditionalParameters("EngineTest");
            e->addCommand(7);
            e->addCommand(2);
            e->update();
            scene->draw(window);

      } else {
        cout << "Veuillez tapez une des commandes suivantes s'il vous plait." << endl;
        cout << "hello : test de l'environement de travail" << endl;
        cout << "state : test des états du jeu" << endl;
        cout << "render : test de l'affichage d'un état" << endl;
        cout << "engine : test du moteur du jeu" << endl;
        cout << "random_ai : test de l'ia aléatoire" << endl;
        cout << "heuristic_ai : test de l'ia aléatoire" << endl;
      }
    }
    return 0;
}

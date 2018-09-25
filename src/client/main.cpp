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

int main(int argc,char* argv[])
{
    Exemple exemple;
    exemple.setX(53);

    //printf("%s\n", argv[1]);
    //printf("%d\n", argc);
    
    if (argc == 2) {
      if ( !strcmp(argv[1],"hello") ){
        cout << "Bonjour le monde!" << endl;
      } else {
        cout << "Veuillez tapez hello s'il vous plait." << endl;
      }
    }

    return 0;
}

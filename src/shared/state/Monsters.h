// Generated by dia2code
#ifndef STATE__MONSTERS__H
#define STATE__MONSTERS__H

#include <string>

namespace state {
  class Character;
}

#include "Character.h"

namespace state {

  /// class Monsters - 
  class Monsters : public state::Character {
    // Attributes
  protected:
    bool ishero     = false;
    // Operations
  public:
    bool isMonster ();
    bool isBoss ();
    Monsters ();
    ~Monsters ();
    Monsters (int life, int att, int spd, int crit, int def, std::string name);
    // Setters and Getters
    bool getIshero() const;
    void setIshero(bool ishero);
  };

};

#endif
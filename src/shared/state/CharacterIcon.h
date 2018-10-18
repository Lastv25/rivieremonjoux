// Generated by dia2code
#ifndef STATE__CHARACTERICON__H
#define STATE__CHARACTERICON__H

#include <string>

namespace state {
  class MobileElements;
}

#include "MobileElements.h"

namespace state {

  /// class CharacterIcon - 
  class CharacterIcon : public state::MobileElements {
    // Attributes
  public:
    int position_x;
    int position_y;
    std::string name;
    // Operations
  public:
    CharacterIcon ();
    ~CharacterIcon ();
    int getx ();
    int gety ();
    void setx (int x);
    void sety (int y);
    // Setters and Getters
  };

};

#endif

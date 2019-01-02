// Generated by dia2code
#ifndef AI__AI__H
#define AI__AI__H

#include <string>
#include <vector>

namespace engine {
  class Engine;
};
namespace state {
  class State;
}

#include "state/State.h"

namespace ai {

  /// class AI - 
  class AI {
    // Attributes
  protected:
    engine::Engine* engine;
    state::State* state;
    std::string stateType;
    // Operations
  public:
    std::vector<std::string> run (std::vector<std::string>& list);
    AI ();
    ~AI ();
    // Setters and Getters
    const engine::Engine*& getEngine() const;
    void setEngine(const engine::Engine*& engine);
    const state::State*& getState() const;
    void setState(const state::State*& state);
    const std::string& getStateType() const;
    void setStateType(const std::string& stateType);
  };

};

#endif

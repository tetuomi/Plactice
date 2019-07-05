#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP
#include "action.hpp"

class Action;

class Master {
  bool brave_turn;
public:
  Master();
  bool get_turn() const;
  void show_status(const Action& action) const;
  void show_damage(const Action& action);
};

#endif

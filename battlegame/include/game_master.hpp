#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP
#include "action.hpp"

class Action;

class Master {
public:
  void show_status(const Action& action);
};

#endif

#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP
#include "action.hpp"
#define CHOICES 4

class Action;

class Master {
  bool brave_turn;
  int selected;
public:
  Master();
  bool get_turn() const;
  int get_selected() const;
  void add_selected();
  void subtract_selected();
  void show_selection() const;
  void show_status(const Action& action) const;
  void show_damage(const Action& action);
};

#endif

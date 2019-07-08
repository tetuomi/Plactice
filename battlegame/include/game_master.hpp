#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP
#include <action.hpp>
#define CHOICES 2

class Action;

class Master {
private:
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
  void show_recovery(const Action& action);
};

#endif

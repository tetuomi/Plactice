#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <dealer.hpp>
#define POSITION_NUMBER 8
#define DISPLAY_CENTER 100
#define CHOICES 3

class Dealer;

class Display
{
private:
  int turn;
  int selected;
public:
  Display();
  int get_turn() const;
  int get_selected() const;
  void show_stones(const Dealer& dealer);
  void add_selected();
  void subtract_selected();
  void switch_turn();
};

#endif

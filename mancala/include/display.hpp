#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#define POSITION_NUMBER 8
#define DISPLAY_CENTER 100
#include <dealer.hpp>


class Dealer;

class Display
{
private:
  int turn;
  int selected;
public:
  Display();
  void show_stones(const Dealer& dealer);
};

#endif

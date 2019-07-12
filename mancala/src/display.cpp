#include <display.hpp>
#include <dealer.hpp>
#include <ncurses.h>


Display::Display()
{
  turn = 1;
  selected = 0;
}

void Display::show_stones(const Dealer& dealer)
{
  for(int i = 1; i < 31; i++)
    mvprintw(10 + i, DISPLAY_CENTER, "|");

  mvprintw(10, DISPLAY_CENTER - 15,"------------------------------");
  mvprintw(20, DISPLAY_CENTER - 15,"------------------------------");
  mvprintw(30, DISPLAY_CENTER - 15,"------------------------------");
  mvprintw(40, DISPLAY_CENTER - 15,"------------------------------");
  
  for(int i = 0; i <= POSITION_NUMBER; i++){
    for(int j = 0; j < dealer.get_pos()[i].get_number(); j++){
      if(i < 3)
        mvprintw( 5 + 10 * (i + 1), DISPLAY_CENTER - 7  + j, "o");
      else if(3 < i && i < 7)
        mvprintw(5 + 10 * (i - 3), DISPLAY_CENTER + 5 + j, "o");
      else if(i == 3)
        mvprintw(8, DISPLAY_CENTER, "o");
      else
        mvprintw(42, DISPLAY_CENTER, "o");
    }
  }
}
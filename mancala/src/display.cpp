#include <display.hpp>
#include <dealer.hpp>
#include <ncurses.h>


Display::Display()
{
  turn = 1;
  selected = 0;
}

void Dealer::show_stones(const Dealer& dealer)
{
  for(int i = 30; i < 61; i++)
    mvaddch(30 + i, 45, "|");

  mvprintw(30,30,"------------------------------");
  mvprintw(50,30,"------------------------------");
  mvprintw(70,30,"------------------------------");
  mvprintw(90,30,"------------------------------");  
  
  for(int i = 0; i < POSITION_NUMBER; i++){
    for(int j = 0; j < dealer.get_pos()[i].number; j++){
      if(i < 3)
        mvaddch(40 + i * 20, 37 + j, "o");
      else if(3 < i && i < 7)
        mvaddch(40 + i * 20, 52 + j, "o");
      else if(i == 3)
        mvaddch(28, 29, "o");
      else
        mvaddch(92, 29, "o");
    }
  }
}

#include <stone.hpp>
#include <dealer.hpp>
#include <display.hpp>
#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  noecho();
  curs_set(0);

  Dealer dealer;
  Display display;

  display.show_stones(dealer);
  while(true)
    {
      const auto buff{getch()};
      if(buff == '\n') break;
    }
  endwin();
}

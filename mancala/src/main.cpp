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

  Stone stone;
  Dealer dealer;
  Display display;

  display.show_stones(dealer);
  
  getch();
  
  endwin();
}

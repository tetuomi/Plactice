#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include <iostream>
#include <ncurses.h>

int main() {
  Person suneo(90,5),brave(120,3);
  initscr();
  noecho();
  std::string buff;
  while(true) {
    for(int i = 0;i < 11;i++)
      for(int j = 0;j < 12;j++)
        mvaddch(i + 1, j + 1 + 30, AA[i][j]);
    
    results(suneo,brave);
    while(1) {
      buff = getch();
      if(buff == "\n") break;
    }
    battle(suneo,brave);
    clear();
  }
  endwin();
  return 0;
}

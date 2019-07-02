#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include "../include/game_master.hpp"
#include <iostream>
#include <ncurses.h>

int main() {
  Person emperor(90,5),brave(120,3);
  Master master;
  initscr();
  noecho();
  std::string buff;
  while(true) {
    for(int i = 0;i < 11;i++)
      for(int j = 0;j < 12;j++)
        mvaddch(i + 1, j + 1 + 50, AA[i][j]);

    master.show_hp(emperor,brave);
    while(1) {
      buff = getch();
      if(buff == "\n"){
        battle(emperor,brave);
        clear();
        break;
      }
    }
    master.show_damage(emperor,brave);
  }
  endwin();
  return 0;
}

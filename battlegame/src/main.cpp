#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include "../include/game_master.hpp"
#include <iostream>
#include <ncurses.h>
// #define KEY_ENTER 0x157

int main() {
  initscr();
  /*
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  */
  noecho();
  // curs_set(0); // 0:invisible
  refresh();

  Person emperor(90,5),brave(120,3);
  Master master;    
  std::string buff;
  
  while(true) {
    for(int i = 0;i < 11;i++)
      for(int j = 0;j < 12;j++)
        mvaddch(i + 1, j + 1 + 50, AA[i][j]);

    master.show_hp(emperor,brave);
    while(true) {
      buff = getch();
      /*
      switch(buff) {
      case KEY_UP:        break;
      case KEY_DOWN:      break;
      case KEY_ENTER:     break;
      }
      */
      if(buff == "\n"){
        battle(emperor,brave,master);
        clear();
        break;
      }
    }
    master.show_damage(emperor,brave);
  }
  endwin();
  return 0;
}

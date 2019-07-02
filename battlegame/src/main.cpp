#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include "../include/game_master.hpp"
#include <iostream>
#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  noecho();
  curs_set(0); // 0:invisible

  
  Person emperor(90,5),brave(120,3);
  Master master;
  while(true) {
    for(int i = 0;i < 11;i++)
      for(int j = 0;j < 12;j++)
        mvaddch(i + 1, j + 1 + 50, AA[i][j]);

    master.show_hp(emperor,brave);
    master.show_selection();
    
    mvaddch(20 + master.get_selected(), 5, '>');
    const auto buff = getch();
    switch(buff) {
      case KEY_UP:    master.subtract_selected(); break;
      case KEY_DOWN:  master.add_selected();      break;
    }
    clear();    
    if(buff == '\n'){
      battle(emperor,brave,master);
      master.show_damage(emperor,brave);
    }
  }
  endwin();
  return 0;
}

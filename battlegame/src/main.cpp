#include <emperor.hpp>
#include <game_master.hpp>
#include <action.hpp>
#include <person.hpp>
#include <iostream>
#include <ncurses.h>

enum SELECTIONS{
  ATACK,
  HEAL
};

int main() {
  initscr();
  start_color();
  init_pair(2, COLOR_GREEN, COLOR_BLUE);
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, FALSE);
  noecho();
  curs_set(0); // 0:invisible
  
  Person emperor(100,5,80),brave(80,3,50);
  Master master;
  Action action(brave,emperor);

  while(true) {
    for(int i = 0;i < 11;i++)
      for(int j = 0;j < 12;j++)
        mvaddch(i + 11, j + 1 + 50, AA[i][j]);

    master.show_status(action);
    master.show_selection();

    const auto buff = getch();
    switch(buff) {
      case KEY_UP:    master.subtract_selected(); break;
      case KEY_DOWN:  master.add_selected();      break;
    }
    clear();
    if(buff == '\n'){
      if(master.get_turn()){
        switch(master.get_selected()){
          case ATACK:
            action.atack(brave,emperor,master);
            master.show_damage(action);
            break;
          case HEAL:
            action.hp_recovery(brave,master);
            master.show_recovery(action);
            break;
        }
      }
      else{
        action.atack(brave,emperor,master);
        master.show_damage(action);
      }
    }
    if(action.judge(brave) || action.judge(emperor)) {
      master.show_status(action);
      master.show_end();
    }
  }
  endwin();
  return 0;
}

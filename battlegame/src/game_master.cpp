#include "../include/game_master.hpp"
#include "../include/person.hpp"
#include <ncurses.h>

void Master::show_damage(const Person& emperor,const Person& brave) {
  if(!brave.get_turn()){
    attron(A_BOLD);
    mvprintw(20, 30, "brave attacked! %2d damages",brave.get_damage());
    attroff(A_BOLD);
  }
  else
    mvprintw(20, 30, "emperor attacked! %2d damages",emperor.get_damage());
}

void Master::show_hp(const Person& emperor,const Person& brave) {
  mvprintw(5,5,"+------------------+");
  mvprintw(6,5,"| Emperor's HP  %3d|",emperor.get_hp());
  mvprintw(7,5,"+------------------+");

  mvprintw(20,70,"+------------------+");
  mvprintw(21,70,"| Brave's HP    %3d|",brave.get_hp());
  mvprintw(22,70,"+------------------+");  
}

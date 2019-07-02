#include "../include/game_master.hpp"
#include "../include/person.hpp"
#include <ncurses.h>
#define CHOICES 4

Master::Master() {
  brave_turn = true;
  selected = 0;
}

void Master::show_selection() {
  if(brave_turn){
    mvprintw(20,6,"atack");
    mvprintw(21,6,"heal");
  }
}

const bool Master::get_turn() const {
  return brave_turn;
}

const int Master::get_selected() const {
  return selected;
}

void Master::add_selected() {
  selected = (selected + 1) % CHOICES;
}

void Master::subtract_selected() {
  selected = (CHOICES + selected - 1) % CHOICES;
}

void Master::show_damage(const Person& emperor,const Person& brave) {
  if(brave_turn){
    attron(A_BOLD);
    mvprintw(20, 30, "brave attacked! %2d damages",brave.get_damage());
    attroff(A_BOLD);
  }
  else
    mvprintw(20, 30, "emperor attacked! %2d damages",emperor.get_damage());

  brave_turn ^= true;
}

void Master::show_hp(const Person& emperor,const Person& brave) {
  mvprintw(5,5,"+------------------+");
  mvprintw(6,5,"| Emperor's HP  %3d|",emperor.get_hp());
  mvprintw(7,5,"+------------------+");

  mvprintw(20,70,"+------------------+");
  mvprintw(21,70,"| Brave's HP    %3d|",brave.get_hp());
  mvprintw(22,70,"+------------------+");  
}

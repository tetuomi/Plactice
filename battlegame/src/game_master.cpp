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
    mvaddch(30 + selected, 5, '>');
    mvprintw(30,6,"atack"); //selected = 0
    mvprintw(31,6,"heal");  //selected = 1
  }
}

const bool Master::get_turn() const {
  return brave_turn;
}

const int Master::get_selected() const{
  return selected;
}

void Master::add_selected() {
  selected = (selected + 1) % CHOICES;
}

void Master::subtract_selected() {
  selected = (CHOICES + selected - 1) % CHOICES;
}

void Master::show_turn() {
  if(brave_turn){
    attron(A_BOLD);
    mvprintw(5, 50, "brave turn !");
    attroff(A_BOLD);
  }
  else
    mvprintw(5, 50, "emperor turn");
 
}

void Master::show_damage(const Person& emperor,const Person& brave) {
  if(brave_turn){
    attron(A_BOLD);
    mvprintw(30, 30, "brave attacked! %2d damages",brave.get_damage());
    attroff(A_BOLD);
  }
  else
    mvprintw(30, 30, "emperor attacked! %2d damages",emperor.get_damage());

  brave_turn ^= true;
}

void Master::show_hp(const Person& emperor,const Person& brave) {
  mvprintw(15,5,"+------------------+");
  mvprintw(16,5,"| Emperor's HP  %3d|",emperor.get_hp());
  mvprintw(17,5,"+------------------+");

  mvprintw(30,70,"+------------------+");
  mvprintw(31,70,"| Brave's HP    %3d|",brave.get_hp());
  mvprintw(32,70,"+------------------+");  
}

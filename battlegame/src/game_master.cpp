#include "../include/game_master.hpp"
#include "../include/action.hpp"
#include <ncurses.h>


Master::Master() {
  brave_turn = true;
  selected = 0;
}

bool Master::get_turn() const {
  return brave_turn;
}

int Master::get_selected() const {
  return selected;
}

void Master::add_selected() {
  selected = (selected + 1) % CHOICES;
}

void Master::subtract_selected() {
  selected = (CHOICES + selected - 1) % CHOICES;
}

void Master::show_selection() const {
  if(brave_turn){
    mvaddch(30 + selected, 5, '>');
    mvprintw(30,6,"atack"); //selected = 0
    mvprintw(31,6,"recovery");  //selected = 1
  }
}

void Master::show_status(const Action& action) const {
  const auto& new_Vstatus{action.get_Vstatus()};
  mvprintw(15,5,"+------------------+");
  mvprintw(16,5,"|  ** Emperor **   |");
  mvprintw(17,5,"| HP            %3d|",new_Vstatus[0].hp);
  mvprintw(18,5,"| MP            %3d|",new_Vstatus[0].mp);
  mvprintw(19,5,"+------------------+");

  mvprintw(30,70,"+------------------+");
  mvprintw(31,70,"|   ** Brave **    |");
  mvprintw(32,70,"| HP            %3d|",new_Vstatus[1].hp);
  mvprintw(33,70,"| MP            %3d|",new_Vstatus[1].mp);
  mvprintw(34,70,"+------------------+");
}

void Master::show_damage(const Action& action){
  if(brave_turn){
    attron(A_BOLD);
    mvprintw(30, 30, "brave attacked! %2d damages",action.get_Vstatus()[1].damage); // const auto& の方が良いのか悪いのか。朝も起きれない。
    attroff(A_BOLD);
  }
  else
    mvprintw(30, 30, "emperor attacked! %2d damages",action.get_Vstatus()[0].damage);

  brave_turn ^= true;
}

void Master::show_recovery(const Action& action) {
  
  if(action.get_Vstatus()[(int)brave_turn].mp_lack) {
    attron(A_BOLD);
    mvprintw(30,30,"MP is lacking!");
    attroff(A_BOLD);
  }
  else {
    if(brave_turn) {
      attron(A_BOLD);
      mvprintw(30, 30, "brave recoveried %2d !",action.get_Vstatus()[1].recovery);
      attroff(A_BOLD);
    }
    else
      mvprintw(30, 30, "emperor recoveried %2d !",action.get_Vstatus()[0].recovery);

    brave_turn ^= true;
  }
}

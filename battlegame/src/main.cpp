#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include <iostream>
#include <ncurses.h>


int main() {
  //setlocale(LC_ALL,"");
  Person suneo(90,5),brave(120,3);
   initscr();
   noecho();
   std::string buff;
  while(true) {
    for(int i = 0;i < 12;i++){
      printw("%s\n",AA[i]);
    }
    results(suneo,brave);
    while(1) {
      buff = getch();
       if(buff == "\n") break;
    }
    battle(suneo,brave);
  }
  endwin();
  return 0;
}

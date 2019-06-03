#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include <iostream>

// #include <ncurses.h>

int main() {
  Person suneo(90,5),brave(120,3);
  // initscr();
  // noecho();
  std::string buff;
  while(1) {
    for(int i = 0;i < 12;i++){
      std::cout << AA[i] << "\n";
    }
    results(suneo,brave);
    while(1) {
      std::cin >> buff;
      if(buff == "g") break;
      // if(getch()) break;
    }
    battle(suneo,brave);
  }
  // endwin();
  return 0;
}

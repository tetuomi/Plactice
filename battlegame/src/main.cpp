#include "../include/emperor.hpp"
#include "../include/person.hpp"
#include <iostream>

int main() {
  Person suneo(100,5),brave(120,3);
  std::string buff;
  while(1) {
    for(int i = 0;i < 12;i++){
      std::cout << AA[i] << "\n";
    }
    results(suneo,brave);
    while(1) {
      std::cin >> buff;
      if(buff == "g") break;
    }
    battle(suneo,brave);
  }
  return 0;
}

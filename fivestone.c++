#include <iostream>
#define WIDTH 8
#define HEIGHT 8
using namespace std;

int main(void){
  for(int a = 0;a < HEIGHT;a++){
    for(int b = 0;b < WIDTH;b++){
      cout << '_';
    }
    cout << '\n';
  }
}

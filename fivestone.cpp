#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

enum DEAL {
  GAME_START,
  SET_INIT_BOARD,
  SCAN_POSITION,
  CHECK_POSITION,
  SET_BORAD,
  JUDGE_BOARD,
  GAME_END
};

string stone_posi[SIZE][SIZE];

enum STONE_TYPE{
  STONE_BLACK,
  STONE_WHITE,
  STONE_NONE
};

string stone_type[3] = {
  "o", //STONE_BLACK
  "x", //STONE_WHITE
  "-"  //STONE_NONE
};

struct stone{
  int X;
  int Y;
};

vector<stone> board;

enum direction{
  DIRECTION_UP,
  DIRECTION_RIGHT_UP,
  DIRECTION_RIGHT,
  DIRECTION_RIGHT_DOWN,
  DIRECTION_MAX
};

int directions[][2] = {
  {-1,0},//DIRECTION_UP
  {-1,1},//DIRECTION_RIGHT_UP
  {0,1},//DIRECTION_RIGHT
  {1,1},//DIRECTION_RIGHT_DOWN
};

int game_start();
int set_init_board();
int scan_position();
int check_position(string _x,string _y);
int set_board();
int judge_board();
int game_end();

int deal = SET_INIT_BOARD;
int turn = STONE_BLACK;
string x,y;

int main(){
  while(1){
    switch(deal){
    case GAME_START:
      deal = game_start();
      break;
    case SET_INIT_BOARD:
      deal = set_init_board();
      break;
    case SCAN_POSITION:
     deal = scan_position();
      break;
    default :
      return 0;
    }
  }
}
int game_start(){
  for(int a = 0;a < SIZE;a++){
    for(int b = 0;b < SIZE;b++){
      stone_posi[a][b] = stone_type[STONE_NONE];
    }
  }
}

int set_init_board(){
  cout << "    (1)(2)(3)(4)(5)(6)(7)(8)(9)(10)(x)\n"; 
  for(int a = 0;a < SIZE;a++){
    cout << "(" << a + 1 << ')';
    for(int b = 0;b < SIZE;b++){
      cout << stone_posi[a][b];
    }
    cout << '\n';
  }
  cout << "(y)\n\n\n";
  return SCAN_POSITION;
}

int scan_position(){
  cout << "Player" << turn + 1 << " decide stone position\n"
       << "x :";
  cin >> x;
  cout << "y :";
  cin >> y;
  return CHECK_POSITION;
}

int check_position(string _x,string _y){
  _x = x,_y = y;
}
/*
int set_board()
int judge_board()
int game_end()
*/

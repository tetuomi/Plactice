#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 9

enum DEAL {
  GAME_START,
  SET_INIT_BOARD,
  SCAN_POSITION,
  CHECK_POSITION,
  BACK_BOARD,
  SET_BOARD,
  JUDGE_BOARD,
  GAME_END,
  DEAL_MAX
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
  {0,-1},//DIRECTION_UP
  {1,-1},//DIRECTION_RIGHT_UP
  {1,0}, //DIRECTION_RIGHT
  {1,1}, //DIRECTION_RIGHT_DOWN
};

int turn = STONE_BLACK;
string x,y;
bool Right_position = true;
int num_x,num_y;
int turn_count;

int game_start(){
  for(int a = 0;a < SIZE;a++){
    for(int b = 0;b < SIZE;b++){
      stone_posi[a][b] = stone_type[STONE_NONE];
    }
  }
  return SET_INIT_BOARD;
}

int set_init_board(){
  cout << "        " << turn_count + 1 << " TIME\n";
  cout << "   1 2 3 4 5 6 7 8 9 (x)\n"; 
  for(int a = 0;a < SIZE;a++){
    cout << ' '<< a + 1;
    for(int b = 0;b < SIZE;b++){
      cout << ' ' << stone_posi[a][b];
    }
    cout << '\n';
  }
  cout << "(y)\n\n\n";
  return SCAN_POSITION;
}

int scan_position(){
  if(!Right_position){
    cout << "Can't Put♡\n\n";
    Right_position = true;
  }
  cout << "Player" << turn + 1 << " decide stone's position\n"
       << "x :";
  cin >> x;
  cout << "y :";
  cin >> y;
  cout << '\n';
  return CHECK_POSITION;
}

int check_position(string _x,string _y){
  num_x = (int)(_x[0] - '0'),num_y = (int)(_y[0] - '0');
  if(_x == "kontetsu" || _y == "kontetsu") return BACK_BOARD;
  if(_x[1] != '\0' || _y[1] != '\0') Right_position = false;
  else if(0 > num_x ||SIZE < num_x || 0 > num_y ||SIZE < num_y ) Right_position = false;
  else if(stone_posi[num_y - 1][num_x - 1] != stone_type[STONE_NONE]) Right_position = false;
  return Right_position? SET_BOARD : SCAN_POSITION;  
}

int back_board(){
  string time;
  bool good_boy = true;
  cout << "What TIME do you want to return?\n"
       << "Say!(int)  :";
  cin >> time;
  if(!none_of(&time[0],&time[time.size() -1],
              [](char x) {return (x < '0' || x > '9');})) good_boy = false;
  if(good_boy){
    int num = stoi(time,nullptr,10);
    if(0 >= num || turn_count < num) good_boy = false;
    else {
      for(int a = turn_count;a >= num;a--){
        stone_posi[board[a - 1].Y - 1][board[a - 1].X - 1] = stone_type[STONE_NONE];
        board.pop_back();
      }
      turn_count = num - 1;
      turn = (num - 1) % 2;
    }
  }
  return good_boy? SET_INIT_BOARD : SCAN_POSITION;
}

int set_board(){
  stone_posi[num_y - 1][num_x - 1] = stone_type[turn];
  cout << "        " << turn_count + 2 << " TIME\n";
  cout << "   1 2 3 4 5 6 7 8 9 (x)\n"; 
  for(int a = 0;a < SIZE;a++){
    cout << ' '<< a + 1;
    for(int b = 0;b < SIZE;b++){
      cout << ' ' << stone_posi[a][b];
    }
    cout << '\n';
  }
  cout << "(y)\n\n\n";
  return JUDGE_BOARD;
}

int connected_stone_count(int _x,int _y){
  int connected_stone_number = 0,max_count = 0;
  for(int a = DIRECTION_UP;a < DIRECTION_MAX;a++){
    connected_stone_number = 0;
    for(int _X = _x,_Y = _y;0 <= _X && _X <= SIZE && 0 <=  _Y && _Y <= SIZE;
        _X += directions[a][0],_Y += directions[a][1]){
      if(stone_posi[_Y - 1][_X - 1] != stone_type[turn]) break; 
      connected_stone_number++;
    }
    connected_stone_number--;
    for(int _X = _x,_Y = _y;0 <= _X && _X <= SIZE && 0 <=  _Y && _Y <= SIZE;
        _X -= directions[a][0],_Y -= directions[a][1]){
      if(stone_posi[_Y - 1][_X - 1] != stone_type[turn]) break;
      connected_stone_number++;
    }
    max_count = (connected_stone_number > max_count)? connected_stone_number : max_count;
  }
  return max_count;
}

int judge_board(int connected_stone){
  if(connected_stone >= 5){
    return GAME_END;
  }
  else {
    board.push_back({num_x,num_y});
    turn_count++;
    turn ^= STONE_WHITE;
    return SCAN_POSITION;
  }
}

int game_end(){
  cout << "Player" << turn + 1 << "'s win!!!!\n\n\n";
  return DEAL_MAX;
}

void game_run(){
  int deal = GAME_START;
  while(1){
    switch(deal){
    case GAME_START : 
      deal = game_start();
      break;
    case SET_INIT_BOARD :
      deal = set_init_board();
      break;
    case SCAN_POSITION :
      deal = scan_position();
      break;
    case CHECK_POSITION :
      deal = check_position(x,y);
      break;
    case BACK_BOARD :
      deal = back_board();
      break;
    case SET_BOARD :
      deal = set_board();
      break;
    case JUDGE_BOARD :
      deal = judge_board(connected_stone_count(num_x,num_y));
      break;
    case GAME_END :
      deal = game_end();
      break;
    default :
      break;
    }
  }
}

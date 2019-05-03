#include <iostream>
#include <vector>
using namespace std;

#define WIDTH 8
#define HEIGHT 8

string x,y;

string stone_posi[HEIGHT][WIDTH];

string stone_name[3] = {
  "o", //STONE_BLACK
  "x", //STONE_WHITE
  "-"  //STONE_NONE
};

int turn;
struct stone{
  int X;
  int Y;
  string stone_type;
};
vector<stone> board;
bool is_not_stone = true;

void set_stone(){
  cout << "   1 2 3 4 5 6 7 8(x)\n";
  for(int a = 0;a < HEIGHT;a++){
     cout << ' ' << a + 1;
    for(int b = 0;b < WIDTH;b++){
      for(int c = 0;c < board.size();c++){
        if(a == board[c].Y && b == board[c].X){
          cout << ' ' << board[c].stone_type;
          is_not_stone = false;
          break;
        }
      }
      if(is_not_stone){
        cout << ' ' << stone_posi[a][b];
      }
       is_not_stone = true;
    }
    cout << '\n';
  }
  cout << "(y)\n\n";
}

bool Check_Can_Put(string _x,string _y){
  if(_x.size() != 1 || _y.size() != 1){
    return false;
  }
  else if('0' >= _x[0] || _x[0] >= '9' ){
    return false;
  }
  for(int a = 0;a < board.size();a++){
    if((int)(_x[0] - '0') - 1 == board[a].X && (int)(_y[0] - '0') - 1 == board[a].Y){
      return false;
    }
  }
  return true;
}
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
/*
int Conectted_Stones_Count(){//判定できない時がある
  int _X,_Y,count,max_count,board_order;
  for(int a = turn;a < board.size();a += 2){
    for(int b = DIRECTION_UP;b < DIRECTION_MAX;b++){
      _X = board[a].X + directions[b][0];
      _Y = board[a].Y + directions[b][1];
      count = 1; board_order = turn;
      while(1){
        if(0 <= _X && _X < 8 && 0 <= _Y && _Y < 8){
          if(_X == board[board_order].X && _Y == board[board_order].Y){
            count++;
            _X += directions[b][0];
            _Y += directions[b][1];
            board_order = turn;
            continue;
          }
          board_order += 2;
          if(board_order >= board.size()){
            max_count =  (count >= max_count)? count : max_count;
           break;
          }
        }
        else {
          break;
        }
      }
    }
    return max_count;
  }
}
*/
int Conectted_Stones_Count(int _x,int _y){
  int _X = _x, _Y = _y, count = 1;
  for(int a = DIRECTION_UP;a < DIRECTION_MAX;a++){
    _X += directions[a][0];
    _Y += directions[a][1];
    while(1){
      if(0 <= _X && _X < 8 && 0 <= _Y && _Y < 8){
        if(board.X == _X && board.Y == _Y){
          count++;
        }
        _X += directions[a][0];
        _Y += directions[a][1];
      }
      else{
        break;
      }
    }
  }
  
}
int main(){
  cout << "   1 2 3 4 5 6 7 8(x)\n";
  for(int a = 0;a < HEIGHT;a++){//初期化
    cout << ' ' << a + 1;
    for(int b = 0;b < WIDTH;b++){
      stone_posi[a][b] =  stone_name[2];
      cout << ' '<< stone_posi[a][b];
    }
    cout << '\n';
  }
  cout << "(y)\n\n";
  while(1){
    while(1) {
      cout << "Player" << turn + 1 << "'s Turn\n";
      cout << "x: ";
      cin >> x;
      cout << "y: ";
      cin >> y;
      cout << "\n";
      if(Check_Can_Put(x,y)){
        break;
      }
      else{
        cout << "Can't Put!!!!\n\n";
      }
    }
   
    board.push_back({(int)(x[0] - '0') - 1,(int)(y[0] - '0') - 1,stone_name[turn]});
    
    set_stone();

  if(Conectted_Stones_Count() == 3){
    cout << "\n\n\n--------------------\n\n";
    cout << "Player" << turn + 1 << " win!!!!!\n\n";
    break;
  }
  turn ^= 1;
  }
}


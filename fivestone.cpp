#include <iostream>
#include <vector>
using namespace std;

#define WIDTH 8
#define HEIGHT 8

string x,y;

string stone_posi[HEIGHT][WIDTH];

string stone_name[3] = {
  "o",//STONE_BLACK
  "x",//STONE_WHITE
  "_"//STONE_NONE
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
  for(int a = 0;a < HEIGHT;a++){
    for(int b = 0;b < WIDTH;b++){
      for(int c = 0;c < board.size();c++){
        if(a == board[c].Y && b == board[c].X){
          cout << board[c].stone_type;
          is_not_stone = false;
          break;
        }
      }
      if(is_not_stone){
        cout << stone_posi[a][b];
      }
       is_not_stone = true;
    }
    cout << '\n';
  }
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
  DIRECTION_DOWN,
  DIRECTION_LEFT_DOWN,
  DIRECTION_LEFT,
  DIRECTION_LEFT_UP,
  DIRECTION_MAX
};

int directions[][2] = {
  {-1,0},//DIRECTION_UP
  {-1,1},//DIRECTION_RIGHT_UP
  {0,1},//DIRECTION_RIGHT
  {1,1},//DIRECTION_RIGHT_DOWN
  {1,0},//DIRECTION_DOWN
  {1,-1},//DIRECTION_LEFT_DOWN
  {0,-1},//DIRECTION_LEFT
  {-1,-1}//DIRECTION_LEFT_UP
};

int Conectted_Stones_Count(){
  int _X,_Y,count,board_order;
  int max_count = 1;  
  for(int a = turn;a < board.size();a += 2){
    for(int b = 0;b < DIRECTION_MAX;b++){
      _X = board[a].X + directions[b][0];
      _Y = board[a].Y + directions[b][1];
      count = 1;board_order = turn;
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
            (count >= max_count)? (max_count = count):(max_count = max_count);
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

int main(){
  for(int a = 0;a < HEIGHT;a++){//初期化
    for(int b = 0;b < WIDTH;b++){
      stone_posi[a][b] =  stone_name[2];
      cout << stone_posi[a][b];
    }
    cout << '\n';
  }
  while(1){
    while(1) {
      cout << "x: ";
      cin >> x;
      cout << "y: ";
      cin >> y;
      if(Check_Can_Put(x,y)){
        break;
      }
    }
   
    board.push_back({(int)(x[0] - '0') - 1,(int)(y[0] - '0') - 1,stone_name[turn]});
    
    set_stone();

  if(Conectted_Stones_Count() == 3){
    cout << "success" ;
    break;
  }
  turn ^= 1;
  }
}


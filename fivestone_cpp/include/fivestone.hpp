#ifndef fivestone_hpp
#define fivestone_hpp

#include <iostream>

int game_start();
void sow_board();
int set_init_board();
int scan_position();
int check_position(std::string _x,std::string _y);
int back_board();
int set_board();
int connected_stone_count(int _x,int _y);
int judge_board(int connected_stone);
int game_end();
void game_run();

#endif

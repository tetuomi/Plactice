#include  "game_master.hpp"
#include <iostream>
#include <vector>

GameMaster::GameMaster(std::size_t player_num)
    : field{"１","２","３","４","５","６","７","８","９"}
    , _turn{1}
    , _player_num{player_num} // 0: player1, 1: player2 が先行
    , winner{Winner::None}
{}

void GameMaster::draw() const
{
    std::cout << "\nーーーーー\n";
    
    for (std::size_t i{0};i < 9;++i)
    {
        std::cout << "|" << field[i];
        if ((i + 1) % 3 == 0)
        {
            std::cout << "|\n";
        }
    }
    
    std::cout << "ーーーーー\n";
}

void GameMaster::game(Player& player1, Player& player2)
{
    std::size_t hand;
    std::cout << (_player_num == 0? " O":" X")<< "のターン\n";
    if (_player_num == 0)
    {
        hand = player1.get_hand();
        field[hand - 1] = " O";
    }
    else
    {
        hand = player2.get_hand();
        field[hand - 1] = " X";
    }

    player1.set_chosen_hands(hand);
    player2.set_chosen_hands(hand);
    
    ++_turn;
    _player_num ^= 1;
}

bool GameMaster::game_end()
{
    bool end_flag = false;
    
    for (std::size_t i{0};i < 3;++i)
    {
        if (field[3 * i] == field[3 * i + 1] && field[3 * i + 1] == field[3 * i + 2])
        {
            end_flag = true;
            winner = Winner::Player;
        }
        if (field[i] == field[i + 3] && field[i + 3] == field[i + 6])
        {
            end_flag = true;
            winner = Winner::Player;
        }
    }

    if (field[0] == field[4] && field[4] == field[8])
    {
        end_flag = true;
        winner = Winner::Player;
    }
    if (field[2] == field[4] && field[4] == field[6])
    {
        end_flag = true;
        winner = Winner::Player;
    }
    
    return _turn == 10 || end_flag;
}

void GameMaster::result() const
{
    if (winner == Winner::Player)
    {
        std::cout << ((_player_num)? "O" : "X") << "のかてぃ\n";
    }
    else
    {
        std::cout << "ひきわけぇ\n";
    }
}

float GameMaster::decide_reward() const
{
    float reward{0};
    if (winner == Winner::Player)
    {
        reward = (_player_num)? 1.0 : -1.0;
    }
    return reward;
}

std::size_t GameMaster::get_turn() const
{
    return _turn;
}

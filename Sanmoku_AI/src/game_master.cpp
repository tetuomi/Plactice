#include  "game_master.hpp"
#include <iostream>
#include <vector>

GameMaster::GameMaster()
    : field{9}
    , turn{1}
    , first_player_turn{true}
    , winner{Winner::None}
{
    std::string string_num[9] = {"１","２","３","４","５","６","７","８","９"};
    for (std::size_t i{0};i < 9;++i)
    {
        field[i] = string_num[i];
    }
}

void GameMaster::draw() const
{
    std::cout << "\n\nーーーーー\n";
    
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

void GameMaster::game(Player& first_player, Player& second_player)
{
    std::size_t hand;
    
    if (first_player_turn)
    {
        hand = first_player.get_hand();
        field[hand - 1] = " O";
    }
    else
    {
        hand = second_player.get_hand();
        field[hand - 1] = " X";
    }

    first_player.set_chosen_hands(hand);
    second_player.set_chosen_hands(hand);
    
    first_player_turn ^= true;
    ++turn;
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
    
    
    return turn == 10 || end_flag;
}

void GameMaster::result() const
{
    if (winner == Winner::Player)
    {
        std::cout << (turn? "O" : "X") << "のかてぃ\n\n";
    }
    else
    {
        std::cout << "ひきわけぇ\n\n";
    }
}

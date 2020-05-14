#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP

#include "person.hpp"
#include "ai.hpp"
#include <iostream> 
#include <vector>


enum class Winner
{
    Player,
    None
};

class GameMaster
{
private:
    std::vector<std::string> field;
    std::size_t _turn;
    std::size_t _player_num;
    Winner winner;
    
public:
    GameMaster(std::size_t player_num);
    void draw() const;
    void game(Player& player1, Player& player2);
    bool game_end();
    void result() const;
    float decide_reward() const;
    std::size_t get_turn() const;
};

#endif

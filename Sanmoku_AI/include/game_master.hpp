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
    std::size_t turn;
    bool first_player_turn;
    Winner winner;
    
public:
    GameMaster();
    void draw() const;
    void game(Player& first_player, Player& second_player);
    bool game_end();
    void result() const;
    float decide_reward() const;
    std::size_t get_turn() const;
};

#endif

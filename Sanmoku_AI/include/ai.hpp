#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"
#include <vector>

enum class Mode
{
    QL,
    RANDOM
};

class AI : public Player
{
private:
    std::vector<std::vector<float>> q_table;
    float epsilon;
    
public:
    AI();
    std::size_t find_q_row(std::size_t before_hands) const;
    std::size_t get_hand() override;
    void update_q_table(bool end_flag, float reward);
    void set_epsilon(float ep);
    void init_param();
    void erase_choosable_hands(std::size_t hand);
};


#endif

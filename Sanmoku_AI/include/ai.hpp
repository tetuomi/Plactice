#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"
#include <vector>

class AI : public Player
{
private:
    std::vector<std::vector<float>> q_table;
    float epsilon;
    std::string filename;
    
public:
    AI(std::string fn);
    std::size_t find_q_row(std::size_t before_hands) const;
    std::size_t get_hand() override;
    void update_q_table(bool end_flag, float reward);
    void set_epsilon(float ep);
    void init_param();
    void save_file() const;
    void load_file();
};


#endif

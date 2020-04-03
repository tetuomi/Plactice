#include "person.hpp"
#include "ai.hpp"
#include "game_master.hpp"
#include "random.hpp"

int main ()
{
    AI ai;
    Random random;

    float init_epsilon = 0.5, epsilon;
    std::size_t episode = 5,reward = 0;
    bool end_flag;
    
    for (std::size_t i{0};i < episode;++i)
    {
        GameMaster master;
        epsilon = init_epsilon * (episode - i) / episode;
        ai.set_epsilon(epsilon);
        while (true)
        {   
            master.draw();             
            master.game(ai, random); // (先行、後攻)
            
            end_flag = master.game_end();
            if (end_flag)
            {
                master.draw();
                reward = master.decide_reward();
                ai.update_q_table(end_flag, reward);
                break;
            }
            if (master.get_turn() != 1)
            {
                ai.update_q_table(end_flag, reward);
            }
        }
        
        master.result();
        ai.init_param();
        random.init_param();
    }
    return 0;
}

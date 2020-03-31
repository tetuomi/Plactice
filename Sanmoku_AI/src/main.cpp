#include "person.hpp"
#include "ai.hpp"
#include "game_master.hpp"

int main ()
{
    Person person;
    AI ai;
    GameMaster master;

    while (true)
    {
        master.draw();                

        if (master.game_end())
        {
            break;
        }
        
        master.game(person, ai);
    }

    master.result();
    
    return 0;
}

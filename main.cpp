#include "game.h"
#include <cstdlib>
#include <ctime>


Game* Game::instance = nullptr;

int main() 
{
    srand(time(nullptr));

    Game* game = Game::getInstance();

    std::vector<int> random_nums;
    for (int i = 1; i <= 100; i++)
        random_nums.push_back(i);
    
    std::random_shuffle(random_nums.begin(), random_nums.end());
    
    for (int i = 0; i < 15; i++) 
        std::cout << random_nums[i] << std::endl;

    FiveEven e;
    FiveOdd o;
    Prime p;
    Multiple10 m10;
    Multiple25 m25;

    Player player1;
    Player player2;
    Player player3;
    Player player4;
    Player player5;

    player1.setStrategy(&e);
    player2.setStrategy(&o);
    player3.setStrategy(&p);
    player4.setStrategy(&m10);
    player5.setStrategy(&m25);

    for (int num : random_nums)
    {
        player1.strategyExecute(num);
        player2.strategyExecute(num);
        player3.strategyExecute(num);
        player4.strategyExecute(num);
        player5.strategyExecute(num);

        if (player1.winner())
        {
            std::cout << "Player 1 wins!" << std::endl;
            break;
        }    
        else if (player2.winner())
        {
            std::cout << "Player 2 wins!" << std::endl;
            break;
        }
        else if (player3.winner())
        {
            std::cout << "Player 3 wins!" << std::endl;
            break;
        }
        else if (player4.winner())
        {
            std::cout << "Player 4 wins!" << std::endl;
            break;
        }
        else if (player5.winner())
        {
            std::cout << "Player 5 wins!" << std::endl;
            break;
        }
    }
    return 0;
}
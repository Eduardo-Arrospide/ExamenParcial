#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_prime(int num)
{
    if (num == 0 || num == 1)
        return false;

    for (int i = 2; i <= num/2; i++) 
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

class Strategy
{
public:
    bool winner = false;

    Strategy() = default;

    virtual void newNumber(int num) = 0;

    bool check_winner()
    {
        return winner;
    }
};

class FiveEven : public Strategy
{
    int numberOfEvens = 0;
public:
    FiveEven() = default;
    void newNumber(int num) override
    {
        if (num % 2 == 0)
            numberOfEvens++;
        if (numberOfEvens == 5)
        {
            std::cout << "Five even numbers win!" << std::endl;
            winner = true;
        }
    }
};

class FiveOdd : public Strategy
{
    int numberOfOdds = 0;
public:
    FiveOdd() = default;
    void newNumber(int num) override
    {
        if (num % 2 == 1)
            numberOfOdds++;
        if (numberOfOdds == 5)
        {
            std::cout << "Five odd numbers win!" << std::endl;
            winner = true;
        }
    }
};

class Prime : public Strategy
{
public:
    Prime() = default;
    void newNumber(int num) override
    {
        if (is_prime(num))
        {
            std::cout << "Prime number win!" << std::endl;
            winner = true;
        }
    }
};

class Multiple10 : public Strategy
{
    int numOfMultiples = 0;
public:
    Multiple10() = default;
    void newNumber(int num) override
    {
        if (num % 10 == 0) 
            numOfMultiples++;
        if (numOfMultiples == 3)
        {
            std::cout << "Three multiples of 10 win!" << std::endl;
            winner = true;
        }
    }
};

class Multiple25 : public Strategy
{
    int numOfMultiples = 0;
public:
    Multiple25() = default;
    void newNumber(int num) override
    {
        if (num % 25 == 0)
            numOfMultiples++;
        if (numOfMultiples == 2)
        {
            std::cout << "Two multiples of 25 win!" << std::endl;
            winner = true;
        }
    }
};

class Player
{
    Strategy* strategy;
public:
    Player() = default;

    void setStrategy(Strategy* s)
    {
        this->strategy = s;
    }

    bool winner()
    {
        strategy->check_winner();
    }

    void strategyExecute(int new_number)
    {
        strategy->newNumber(new_number);
    }
};

class Game
{
    static Game *instance;

    Game() = default;

public: 
    static Game *getInstance() 
    {
        if (instance == nullptr)
            instance = new Game();
        return instance;
    }    
};


#endif // GAME_H
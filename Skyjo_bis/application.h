#pragma once
#include <memory>
#include <iostream>
#include "game.h"
#define APPLICATION_DEBUG true

class Application
{
private:
    std::unique_ptr<Game> m_game;
public:
    Application()
    {
        #ifdef APPLICATION_DEBUG
            std::cout << "Application created at address: " << this << std::endl;
        #endif // APPLICATION_DEBUG
    }
    ~Application()
    {
        #ifdef APPLICATION_DEBUG
                std::cout << "Application destroyed at address: " << this << std::endl;
        #endif // APPLICATION_DEBUG
	}

    Game& get_game() { return *m_game; }

    void start_game(const std::vector<Strategy::StrategyType>& strategies);
    void print_application();
};

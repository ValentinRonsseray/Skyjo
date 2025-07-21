// Define the inline function after the Game class is fully declared
#include "application.h"
#include "game.h"
#include "strategy.h"

void Application::start_game(const std::vector<Strategy::StrategyType>& strategies)
{
	if (m_game)
	{
		std::cout << "Game already started." << std::endl;
		return;
	}
	m_game = std::make_unique<Game>(*this, strategies);
}

void Application::print_application()
{
	std::cout << "Application with game." << std::endl;
	if (m_game)
	{
		m_game->print_game();
	}
	else
	{
		std::cout << "No game started." << std::endl;
	}
}

// Define the inline function after the Game class is fully declared
#include "application.h"
#include "game.h"

void Application::start_game(unsigned int player_amount)
{
    m_game = std::make_unique<Game>(*this, player_amount);
	m_game->game_loop();
}

unsigned int Application::setup_game()
{
	unsigned int player_amount;
	std::cout << "Enter the number of players (2-8): ";
	std::cin >> player_amount;
	while (player_amount < 2 || player_amount > 8)
	{
		std::cout << "Invalid number of players. Please enter a number between 2 and 8: ";
		std::cin >> player_amount;
	}
	return player_amount;
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

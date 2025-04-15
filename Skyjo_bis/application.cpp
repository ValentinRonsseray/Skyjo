// Define the inline function after the Game class is fully declared
#include "application.h"
#include "game.h"

void Application::start_game(unsigned int player_amount)
{
    m_game = std::make_unique<Game>(*this, player_amount);
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

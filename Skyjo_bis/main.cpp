#include <iostream>
#include "application.h"
#include "constants.h"
#include "strategy.h"

int main()
{
	try
	{
		const std::vector<Strategy::StrategyType> strategies = {
			Strategy::StrategyType::HUMAN_STRATEGY, // Player 1
			Strategy::StrategyType::HUMAN_STRATEGY, // Player 2
		};
		Application app;
		app.start_game(2);
		Game& game = app.get_game();
		game.game_loop();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown exception occurred." << std::endl;
		return 1;
	}

	return 0;
}

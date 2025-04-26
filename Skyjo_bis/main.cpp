#include <iostream>
#include "application.h"

int main()
{
	try
	{
		Application app;
		const unsigned int player_amount = app.setup_game();
		app.start_game(player_amount);
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

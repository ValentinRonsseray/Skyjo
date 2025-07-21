#include "human_strategy.h"

size_t HumanStrategy::choose_card_to_replace(Deck player_deck) const
{
	// Get the Array Position of the card to replace (tuple<size_t, size_t>)
	size_t row, column;
	std::cout << "Enter the row and column of the card to replace:\n";
	std::cout << "Row (1 to 3): ";
	std::cin >> row;
	std::cout << "Column (1 to 4): ";
	std::cin >> column;

	// Check if the input is valid
	if (std::cin.fail() || row < 1 || row > 3 || column < 1 || column > 4)
	{
		std::cin.clear(); // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		std::cout << "Invalid input. Please enter a valid row (1-3) and column (1-4)." << std::endl;
		return choose_card_to_reveal(player_deck); // Retry
	}

	// Conversion to 0-based index
	row -= 1;
	column -= 1;
	return row * 4 + column;
}

size_t HumanStrategy::choose_card_to_reveal(Deck player_deck) const
{
	// Get the Array Position of the card to reveal (tuple<size_t, size_t>)
	size_t row, column;
	std::cout << "Enter the row and column of the card to reveal:\n";
	std::cout << "Row (1 to 3): ";
	std::cin >> row;
	std::cout << "Column (1 to 4): ";
	std::cin >> column;

	// Check if the input is valid
	if (std::cin.fail() || row < 1 || row > 3 || column < 1 || column > 4)
	{
		std::cin.clear(); // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		std::cout << "Invalid input. Please enter a valid row (1-3) and column (1-4)." << std::endl;
		return choose_card_to_reveal(player_deck); // Retry
	}

	// Conversion to 0-based index
	row -= 1;
	column -= 1;
	return row * 4 + column;
}

Strategy::DrawCardSourceEnum HumanStrategy::choose_where_to_draw() const
{
	std::string decision;
	std::cout << "Do you want to draw from the draw pile or discard pile? (d/draw / t/discard): ";
	std::cin >> decision;
	if (decision == "d" || decision == "discard")
	{
		return DrawCardSourceEnum::DRAW_PILE;
	}
	else if (decision == "t" || decision == "draw")
	{
		return DrawCardSourceEnum::DISCARD_PILE;
	}
	else
	{
		std::cout << "Invalid input. Please enter 'd' or 't'." << std::endl;
		return choose_where_to_draw(); // Retry
	}
}

Strategy::CardDecisionEnum HumanStrategy::choose_discard_or_replace() const
{
	std::string decision;
	std::cout << "Do you want to replace or discard the card? (r/replace / d/discard): ";
	std::cin >> decision;
	if (decision == "r")
	{
		return CardDecisionEnum::REPLACE;
	}
	else if (decision == "d")
	{
		return CardDecisionEnum::DISCARD;
	}
	else
	{
		std::cout << "Invalid input. Please enter 'r' or 'd'." << std::endl;
		return choose_discard_or_replace(); // Retry
	}
}
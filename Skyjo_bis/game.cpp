#include "game.h"
#include <random>

std::vector<Card> Game::build_cards_vector()
{
	std::vector<Card> cards;
	cards.reserve(Constants::Card::CARD_NUMBER);
	for (const auto& [points, frequency] : Constants::Card::CARD_FREQUENCY)
	{
		for (unsigned int i = 0; i < frequency; ++i)
		{
			cards.push_back(Card(points));
		}
	}

	return cards;
}

void Game::shuffle_cards()
{
	std::vector<Card*> draw_pile_cards = m_draw_pile.get_cards();
	std::random_device rd;  // Obtain a random number from hardware
	std::mt19937 eng(rd()); // Seed the generator
	std::shuffle(draw_pile_cards.begin(), draw_pile_cards.end(), eng);
}
#include "game.h"

void Game::initialize_cards_vector()
{
	for (const auto& [points, frequency] : Constants::Card::CARD_FREQUENCY)
	{
		for (unsigned int i = 0; i < frequency; ++i)
		{
			m_cards.push_back(Card(points));
		}
	}
}

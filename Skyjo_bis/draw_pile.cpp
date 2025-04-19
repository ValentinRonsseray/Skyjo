#include "draw_pile.h"
#include <random>

void DrawPile::shuffle_cards()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
}

void DrawPile::distribute_cards(std::vector<Player>& players)
{
    const size_t PLAYER_COUNT = players.size();
    const size_t CARDS_PER_PLAYER = Constants::Deck::N_ROW * Constants::Deck::N_COL;
    const size_t TOTAL_NEEDED = PLAYER_COUNT * CARDS_PER_PLAYER;

	// Check if there are enough cards in the deck
    if (m_cards.size() < TOTAL_NEEDED) {
		throw std::runtime_error("Not enough cards in the deck to distribute.");
    }

	for (size_t j = 0; j < CARDS_PER_PLAYER; ++j)
	{
		for (size_t k = 0; k < PLAYER_COUNT; ++k)
		{
			players[k].get_deck().set_card_and_visibility_in_deck(j, m_cards.back(), false);
			m_cards.pop_back();
		}
	}
}

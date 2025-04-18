#include "player.h"
#include <iostream>
#include "game.h"

int Player::get_score() const
{
	return m_deck.get_score();
}

void Player::discard_card(DiscardPile& discard_pile)
{
	m_deck.discard_card(discard_pile);
}

void Player::print_state() const
{
	std::cout << "Player " << this << " :\n";
		
	// Display deck cards in a 3 * 4 grid
	int index = 0;
	for (const auto& card_in_deck : m_deck)
	{
		if (card_in_deck.card != nullptr && card_in_deck.is_visible)
		{
			std::cout << " " << card_in_deck.card->get_points() << " ";
		}
		else
		{
			std::cout << " -- ";
		}

		index++;
		if (index % Constants::Deck::N_COL == 0)
		{
			std::cout << "\n";
		}
	}

	// Display score
	std::cout << "Score: " << get_score() << "\n";

	// Display extra card
	Card* extra_card = m_deck.get_extra_card();
	if (extra_card != nullptr)
	{
		std::cout << "Extra card: " << extra_card->get_points() << "\n";
	}
	else
	{
		std::cout << "No extra card.\n";
	}

}

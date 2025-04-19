#include "pile.h"
#include "draw_pile.h"
#include "discard_pile.h"
#include <stdexcept>
#include <iostream>

Card* Pile::pick_top_card()
{
	if (m_cards.empty())
	{
		throw std::runtime_error("No cards in the pile.");
	}

	Card* top_card = m_cards.back();
	m_cards.pop_back();

	return top_card;
}

void Pile::print_state() const
{
	// If it is a draw pile, print the number of card
	bool is_draw_pile = dynamic_cast<const DrawPile*>(this) != nullptr;
	if (is_draw_pile)
	{
		std::cout << "Draw pile (" << m_cards.size() << " cards):\n";
	}
	else // If it is a discard pile, print the number of cards and the top card
	{
		std::cout << "Discard pile (" << m_cards.size() << " cards):\n";
		if (!m_cards.empty())
		{
			std::cout << "\tTop card: " << m_cards.back()->get_points() << "\n";
		}
	}
}

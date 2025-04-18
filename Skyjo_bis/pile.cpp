#include "pile.h"
#include <stdexcept>

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

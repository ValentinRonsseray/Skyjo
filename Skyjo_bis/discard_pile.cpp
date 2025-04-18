#include "discard_pile.h"
#include <stdexcept>

void DiscardPile::add_card(Card* card)
{
	if (card != nullptr)
	{
		m_cards.push_back(card);
	}
	else
	{
		throw std::invalid_argument("Cannot add a null card to the discard pile.");
	}
}

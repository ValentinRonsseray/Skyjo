#include "deck.h"

int Deck::get_score() const
{
	int score = 0;
	for (const auto& card_in_deck : m_deck_cards)
	{
		if (card_in_deck.is_visible && card_in_deck.card != nullptr)
		{
			score += card_in_deck.card->get_points();
		}
	}
	return score;
}

void Deck::discard_card(DiscardPile& discard_pile)
{
	if (m_extra_card != nullptr)
	{
		discard_pile.add_card(m_extra_card);
		set_extra_card(nullptr);
	}
	else
	{
		throw std::runtime_error("No extra card to discard.");
	}
}
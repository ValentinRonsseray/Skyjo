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

void Deck::replace_card(DiscardPile& discard_pile, size_t card_index)
{
	if (card_index < get_size())
	{
		discard_pile.add_card(m_deck_cards[card_index].card);
		m_deck_cards[card_index].card = m_extra_card;
		m_extra_card = nullptr;
	}
	else
	{
		throw std::out_of_range("Card index out of range");
	}
}
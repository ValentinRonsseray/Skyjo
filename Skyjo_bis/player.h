#pragma once
#include "deck.h"

class Player
{
private:
	Deck m_deck;
public:
	Player() = default;

	inline Deck& get_deck() { return m_deck; }
	int get_score() const;

	inline void set_card_in_deck(size_t index, Card* card, bool is_visible)
	{
		m_deck.set_card_in_deck(index, card, is_visible);
	}
	inline void set_extra_card(Card* card)
	{
		m_deck.set_extra_card(card);
	}

	void print_state() const;
};

#pragma once
#include "pile.h"
class DiscardPile :
    public Pile
{
public:
	DiscardPile() : Pile(nullptr, {}) {}
    DiscardPile(Game* game, std::vector<Card*> cards) : Pile(game, cards) {}

	std::vector<Card*> get_cards() const { return m_cards; }

    inline bool is_empty() const { return m_cards.empty(); }
};


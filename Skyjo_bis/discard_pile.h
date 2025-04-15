#pragma once
#include "pile.h"
class DiscardPile :
    public Pile
{
public:
	DiscardPile() : Pile(nullptr, {}) {}
    DiscardPile(Game* game, std::vector<Card*> cards) : Pile(game, cards) {}
};


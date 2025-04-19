#pragma once
#include <vector>
#include "card.h"

class Game;

class Pile
{
protected:
	Game* m_game;
	std::vector<Card*> m_cards;
public:
	Pile() : m_game(nullptr), m_cards({}) {}
	Pile(Game* game, std::vector<Card*> cards) : m_game(game), m_cards(cards) {}
	virtual ~Pile() = default;

	Card* pick_top_card();
	void print_state() const;
};


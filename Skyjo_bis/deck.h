#pragma once
#include <array>
#include "card.h"
#include "constants.h"
class Deck
{
private:
	std::array<Card*, Constants::Deck::N_ROW * Constants::Deck::N_COL> m_cards;
	std::array<bool, Constants::Deck::N_ROW* Constants::Deck::N_COL> m_visibilities;
	Card* extra_card;
public:
	Deck() : m_cards({}), m_visibilities({}), extra_card(nullptr) {};
};


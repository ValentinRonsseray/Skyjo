#pragma once
#include <iostream>
#include <string>
#include "deck.h"

class Strategy
{
public:

	enum class DrawCardSourceEnum
	{
		DRAW_PILE,
		DISCARD_PILE
	};

	enum class CardDecisionEnum
	{
		REPLACE,
		DISCARD,
	};

	Strategy() = default;

	/**
	 * @brief Gets the index of the card to replace.
	 * @return The index of the card to replace. (0 <= index <= 11)
	 */
	size_t choose_card_to_replace() const;

	/**
	 * @brief Gets the index of the card to reveal.
	 * @return The index of the card to reveal. (0 <= index <= 11)
	 */
	size_t choose_card_to_reveal() const;
	
	DrawCardSourceEnum choose_where_to_draw() const;

	CardDecisionEnum choose_discard_or_replace() const;
};


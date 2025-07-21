#pragma once
#include <iostream>
#include <string>
#include "deck.h"

class Strategy
{
public:

	enum class StrategyType
	{
		HUMAN_STRATEGY,
		RANDOM_STRATEGY,
	};

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

	static std::unique_ptr<Strategy> create_strategy(StrategyType strategy_type);

	/**
	 * @brief Choose an available card to replace in the player's deck.
	 * @return The index of the card to replace. (0 <= index <= 11)
	 */
	virtual size_t choose_card_to_replace(Deck player_deck) const = 0;

	/**
	 * @brief Choose a hidden card to reveal in the player's deck.
	 * @return The index of the card to reveal. (0 <= index <= 11)
	 */
	virtual size_t choose_card_to_reveal(Deck player_deck) const = 0;

	virtual DrawCardSourceEnum choose_where_to_draw() const = 0;

	virtual CardDecisionEnum choose_discard_or_replace() const = 0;
};


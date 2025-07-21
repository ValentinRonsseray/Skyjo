#pragma once
#include "deck.h"
#include "strategy.h"

class Player
{
private:
	Deck m_deck;
	std::unique_ptr<Strategy> m_strategy;
public:
	Player(Strategy::StrategyType strategy_type)
	{
		m_strategy = Strategy::create_strategy(strategy_type);
	}

	inline Deck& get_deck() { return m_deck; }
	int get_score() const;

	inline Card* get_card_in_deck(size_t index) const
	{
		return m_deck.get_card_in_deck(index);
	}
	inline bool get_card_visibility(size_t index) const
	{
		return m_deck.get_card_visibility(index);
	}
	inline Card* get_extra_card() const
	{
		return m_deck.get_extra_card();
	}
	std::vector<int> get_non_removed_columns() const;

	inline void set_card_and_visibility_in_deck(size_t index, Card* card, bool is_visible)
	{
		m_deck.set_card_and_visibility_in_deck(index, card, is_visible);
	}
	inline void set_extra_card(Card* card)
	{
		m_deck.set_extra_card(card);
	}

	bool has_every_cards_visible() const;

	/**
	 * @brief Returns the index of the column if all its cards are visible and have the same points. Otherwise returns -1.
	 */
	int check_for_removable_column() const;
	/**
	 * @brief Removes the column at the given index from the deck.
	 * @param index The index of the column to remove. (0 <= index <= 3)
	 */
	void remove_column(int column_index);
	/**
	 * @brief Discards the extra card.
	 * @param discard_pile The discard pile to which the card will be discarded.
	 */
	void discard_card(DiscardPile& discard_pile);
	/**
	 * @brief Replaces the card at the given index with the extra card.
	 * @param discard_pile The discard pile to which the replaced card will be discarded.
	 * @param card_index The index of the card to be replaced. (0 <= card_index <= 11)
	 */
	void replace_card(DiscardPile& discard_pile, size_t card_index);
	/**
	 * @brief Reveals all cards in the deck.
	 */
	void reveal_card(size_t deck_index);
	void reveal_all_cards();

	size_t choose_card_to_replace() const;
	size_t choose_card_to_reveal() const;
	Strategy::DrawCardSourceEnum choose_where_to_draw() const;
	Strategy::CardDecisionEnum choose_discard_or_replace() const;

	/**
	 * @brief Prints the state of the player, including the deck and score.
	 */
	void print_state() const;
};

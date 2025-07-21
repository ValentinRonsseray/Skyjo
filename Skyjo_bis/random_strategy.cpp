#include "random_strategy.h"
#include "deck.h"
#include "utils.h"

size_t RandomStrategy::choose_card_to_replace(Deck player_deck) const
{
	std::vector<size_t> replacable_indices = player_deck.get_replacable_card_indices();

	// Exception if no card is replacable
	if (replacable_indices.empty())
	{
		throw std::runtime_error("No card is replacable.");
	}

	// Pick a random index from the replacable indices
	size_t random_index = Utils::pick_random_element_in_vector(replacable_indices);

	return random_index;
}

size_t RandomStrategy::choose_card_to_reveal(Deck player_deck) const
{
	std::vector<size_t> hidden_indices = player_deck.get_hidden_card_indices();

	// Exception if no card is hidden
	if (hidden_indices.empty())
	{
		throw std::runtime_error("Trying to reveal a card from a deck with no hidden card.");
	}

	// Pick a random index from the hidden indices
	size_t random_index = Utils::pick_random_element_in_vector(hidden_indices);

	return random_index;
}

Strategy::DrawCardSourceEnum RandomStrategy::choose_where_to_draw() const
{
	std::vector<Strategy::DrawCardSourceEnum> piles = {
		Strategy::DrawCardSourceEnum::DRAW_PILE,
		Strategy::DrawCardSourceEnum::DISCARD_PILE
	};

	Strategy::DrawCardSourceEnum random_source = Utils::pick_random_element_in_vector(piles);

	return random_source;
}

Strategy::CardDecisionEnum RandomStrategy::choose_discard_or_replace() const
{
	std::vector<Strategy::CardDecisionEnum> decisions = {
		Strategy::CardDecisionEnum::REPLACE,
		Strategy::CardDecisionEnum::DISCARD
	};

	Strategy::CardDecisionEnum random_decision = Utils::pick_random_element_in_vector(decisions);

	return random_decision;
}
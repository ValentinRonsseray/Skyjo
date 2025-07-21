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

std::vector<int> Deck::get_non_removed_columns() const
{
	std::vector<int> non_removed_columns = {};
	for (size_t j = 0; j < Constants::Deck::N_COL; j++)
	{
		bool column_removed = true;
		Card* card = get_card_in_deck(j * Constants::Deck::N_COL);
		bool card_is_visible = get_card_visibility(j * Constants::Deck::N_COL);
		if (card == nullptr && card_is_visible)
		{
			non_removed_columns.push_back(static_cast<int>(j));
		}
	}
	return non_removed_columns;
}

std::vector<size_t> Deck::get_replacable_card_indices() const
{
	std::vector<size_t> replacable_indices;
	for (size_t i = 0; i < m_deck_cards.size(); ++i)
	{
		if (m_deck_cards[i].card != nullptr)
		{
			if (m_deck_cards[i].is_visible)
			{
				replacable_indices.push_back(i);
			}
		}
	}
	return replacable_indices;
}

std::vector<size_t> Deck::get_hidden_card_indices() const
{
	std::vector<size_t> hidden_indices;
	for (size_t i = 0; i < m_deck_cards.size(); ++i)
	{
		if (m_deck_cards[i].card != nullptr && !m_deck_cards[i].is_visible)
		{
			hidden_indices.push_back(i);
		}
	}
	return hidden_indices;
}


bool Deck::has_every_cards_visible() const
{
	for (const auto& card : m_deck_cards) {
		if (!card.is_visible) {
			return false;
		}
	}
	return true;
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
		m_deck_cards[card_index].is_visible = true;
		m_extra_card = nullptr;
	}
	else
	{
		throw std::out_of_range("Card index out of range");
	}
}
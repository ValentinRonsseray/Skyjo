#include "player.h"
#include <iostream>
#include "game.h"

int Player::get_score() const
{
	return m_deck.get_score();
}

bool Player::has_every_cards_visible() const
{
	return m_deck.has_every_cards_visible();
}

int Player::check_for_removable_column() const
{
	for (size_t j = 0; j < Constants::Deck::N_COL; j++)
	{
		bool column_removable = true;
		int points = 0;
		for (size_t i = 0; i < Constants::Deck::N_ROW; i++)
		{
			if (get_card_in_deck(j + i * Constants::Deck::N_ROW) == nullptr || !get_card_visibility(j))
			{
				break;
			}

			if (i == 0)
			{
				points = get_card_in_deck(j)->get_points();
			}

			if (get_card_in_deck(j + i * Constants::Deck::N_ROW)->get_points() != points)
			{
				column_removable = false;
				break;
			}
		}
		if (column_removable)
		{
			return static_cast<int>(j);
		}
	}

	return static_cast<int>(-1);
}

void Player::remove_column(int column_index)
{
	if (column_index < 0 || column_index >= Constants::Deck::N_COL)
	{
		throw std::out_of_range("Column index out of range.");
	}

	for (size_t j = 0; j < Constants::Deck::N_ROW; j++)
	{
		m_deck.set_card_and_visibility_in_deck(column_index + j * Constants::Deck::N_COL, nullptr, false);
	}
}

void Player::discard_card(DiscardPile& discard_pile)
{
	m_deck.discard_card(discard_pile);
}

void Player::replace_card(DiscardPile& discard_pile, size_t card_index)
{
	m_deck.replace_card(discard_pile, card_index);
}

void Player::print_state() const
{
	std::cout << "Player " << this << " :\n";
		
	// Display deck cards in a 3 * 4 grid
	int index = 0;
	for (const auto& card_in_deck : m_deck)
	{
		if (card_in_deck.card != nullptr && card_in_deck.is_visible)
		{
			std::cout << " " << card_in_deck.card->get_points() << " ";
		}
		else
		{
			std::cout << " -- ";
		}

		index++;
		if (index % Constants::Deck::N_COL == 0)
		{
			std::cout << "\n";
		}
	}

	// Display score
	std::cout << "Score: " << get_score() << "\n";

	// Display extra card
	Card* extra_card = m_deck.get_extra_card();
	if (extra_card != nullptr)
	{
		std::cout << "Extra card: " << extra_card->get_points() << "\n";
	}
	else
	{
		std::cout << "No extra card.\n";
	}

}

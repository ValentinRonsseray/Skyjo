#include "game.h"
#include <random>

std::vector<Card> Game::build_cards_vector()
{
	std::vector<Card> cards;
	cards.reserve(Constants::Card::CARD_NUMBER);
	for (const auto& [points, frequency] : Constants::Card::CARD_FREQUENCY)
	{
		for (unsigned int i = 0; i < frequency; ++i)
		{
			cards.push_back(Card(points));
		}
	}

	return cards;
}

void Game::print_state() const
{
	std::cout << "Game " << this << " :\n";
	for (const auto& player : m_players)
	{
		player.print_state();
		std::cout << "\n";
	}
	std::cout << "Draw pile size: " << m_draw_pile.get_cards().size() << "\n";
}

void Game::shuffle_cards()
{
	m_draw_pile.shuffle_cards();
}

void Game::distribute_cards()
{
	m_draw_pile.distribute_cards(m_players);
}

void Game::pick_card_from_draw_pile(Player& player) const
{
	if (m_draw_pile.is_empty())
	{
		throw std::runtime_error("Draw pile is empty.");
	}

	Card* card = m_draw_pile.get_cards().back();
	m_draw_pile.get_cards().pop_back();
	player.set_extra_card(card);
}

void Game::pick_card_from_discard_pile(Player& player)
{
	if (m_discard_pile.is_empty())
	{
		throw std::runtime_error("Discard pile is empty.");
	}

	Card* card = m_discard_pile.get_cards().back();
	m_discard_pile.get_cards().pop_back();
	player.set_extra_card(card);
}

void Game::discard_card(Player& player, DiscardPile& discard_pile)
{
	player.discard_card(discard_pile);
}
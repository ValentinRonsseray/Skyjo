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

void Game::reveal_card(Player& player, size_t deck_index)
{
	const size_t max_index = static_cast<size_t>(Constants::Deck::N_ROW * Constants::Deck::N_COL) - 1;
	if (deck_index <= max_index)
	{
		player.set_card_and_visibility_in_deck(deck_index, player.get_card_in_deck(deck_index), true);
	}
	else
	{
		throw std::out_of_range("Deck index out of range.");
	}
}
void Game::pick_card_from_draw_pile(Player& player)
{
	Card* card = m_draw_pile.pick_top_card();
	player.set_extra_card(card);
}

void Game::pick_card_from_discard_pile(Player& player)
{
	if (m_discard_pile.is_empty())
	{
		throw std::runtime_error("Discard pile is empty.");
	}

	Card* card = m_discard_pile.pick_top_card();
	player.set_extra_card(card);
}

int Game::check_for_removable_column(Player& player)
{
	return player.check_for_removable_column();
}

void Game::remove_column(Player& player, int column_index)
{
	if (column_index < 0 || column_index >= Constants::Deck::N_COL)
	{
		throw std::out_of_range("Column index out of range.");
	}
	player.remove_column(column_index);
}

void Game::discard_card(Player& player, DiscardPile& discard_pile)
{
	player.discard_card(discard_pile);
}

void Game::discard_draw_pile_top_card()
{
	if (!m_draw_pile.is_empty())
	{
		Card* top_card = m_draw_pile.pick_top_card();
		m_discard_pile.add_card(top_card);
	}
	else
	{
		throw std::runtime_error("Draw pile is empty.");
	}
}

bool Game::check_game_over() const
{
	bool game_over = true;
	for (const auto& player : m_players)
	{
		game_over = player.has_every_cards_visible();
		if (!game_over)
		{
			break;
		}
	}

	return game_over;
}

Player* Game::next_player(Player& player)
{
    auto it = std::find_if(m_players.begin(), m_players.end(), [&](const Player& p) {
        return &p == &player;
    });
    if (it != m_players.end())
    {
        ++it;
        if (it == m_players.end())
        {
            it = m_players.begin();
        }
        return &(*it);
    }
    else
    {
        throw std::runtime_error("Player not found in the game.");
    }
}
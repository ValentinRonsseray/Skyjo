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
	m_discard_pile.print_state();
	m_draw_pile.print_state();
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

void Game::play_turn(Player& player, bool a_player_has_revealed_all_cards)
{
	// Draw card from the draw pile or discard pile
	UserInputHandler::DrawCardSourceEnum source = m_user_input_handler.choose_where_to_draw();
	if (source == UserInputHandler::DrawCardSourceEnum::DRAW_PILE)
	{
		pick_card_from_draw_pile(player);
		player.get_extra_card()->get_points();
		std::cout << "You picked the card: " << player.get_extra_card()->get_points() << "\n";

		// Choose to discard or replace
		UserInputHandler::CardDecisionEnum decision = m_user_input_handler.choose_discard_or_replace();
		if (decision == UserInputHandler::CardDecisionEnum::REPLACE)
		{
			size_t card_index = m_user_input_handler.choose_card_to_replace();
			player.replace_card(m_discard_pile, card_index);
			int removable_column = check_for_removable_column(player);
			if (removable_column != -1)
			{
				remove_column(player, removable_column);
				std::cout << "Column " << removable_column << " removed.\n";
			}
			
		}
		else if (decision == UserInputHandler::CardDecisionEnum::DISCARD)
		{
			discard_card(player, m_discard_pile);

			// Choose a card to reveal
			size_t deck_index = 0;
			bool chosen_card_already_releaved = true;
			while (chosen_card_already_releaved)
			{
				size_t deck_index = m_user_input_handler.choose_card_to_reveal();
				if (player.get_card_visibility(deck_index))
				{
					std::cout << "This card is already revealed. Please choose another one.\n";
				}
				else
				{
					reveal_card(player, deck_index);
					chosen_card_already_releaved = false;
				}
}
}
}
	else // source == UserInputHandler::DrawCardSourceEnum::DISCARD_PILE
	{
		pick_card_from_discard_pile(player);
		player.get_extra_card()->get_points();
		std::cout << "You picked the card: " << player.get_extra_card()->get_points() << "\n";

		// Replace one of the cards in the deck
		size_t card_index = m_user_input_handler.choose_card_to_replace();
		player.replace_card(m_discard_pile, card_index);
		int removable_column = check_for_removable_column(player);
		if (removable_column != -1)
		{
			remove_column(player, removable_column);
			std::cout << "Column " << removable_column << " removed.\n";
}
}

	if (a_player_has_revealed_all_cards)
	{
		player.reveal_all_cards();
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

Player* Game::designate_first_player()  
{  
	// For now, simply pick a random player from the list of players
	// The accurate way to pick the first player is to be implemented in the future

	// But before we need to reveal two cards for each player
	for (auto& player : m_players)
	{
		reveal_card(player, 9);
		reveal_card(player, 10);
	}

	// And the discard pile must have one card
	discard_draw_pile_top_card();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, m_player_amount - 1);
	size_t random_index = static_cast<size_t>(dis(gen));
	return &m_players[random_index];
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
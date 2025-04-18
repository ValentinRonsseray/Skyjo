#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "card.h"
#include "player.h"
#include "draw_pile.h"
#include "discard_pile.h"
#include "constants.h"
#define GAME_DEBUG true

class Application;

class Game
{
public:
	Game(Application& application, unsigned int player_amount) : m_application(application), m_player_amount(player_amount), m_players(player_amount, Player()), m_discard_pile(this, {})
	{
		#ifdef GAME_DEBUG
			std::cout << "Game created at address: " << this << std::endl;
		#endif // GAME_DEBUG

		m_cards = build_cards_vector();

		std::vector<Card*> cards_ptrs;
		cards_ptrs.reserve(Constants::Card::CARD_NUMBER);
		for (auto& card : m_cards)
		{
			cards_ptrs.push_back(&card);
		}

		m_draw_pile = DrawPile(this, cards_ptrs);
	};
	~Game()
	{
		#ifdef GAME_DEBUG
				std::cout << "Game destroyed at address: " << this << std::endl;
		#endif // GAME_DEBUG
	};

	void print_game() const
	{
		std::cout << "Game with " << m_player_amount << " players." << std::endl;
	}
	void print_state() const;

	inline std::vector<Player>& get_players() { return m_players; }
	inline int get_score(Player& player) const { return player.get_score(); }

	void shuffle_cards();
	void distribute_cards();
	void pick_card_from_draw_pile(Player& player);
	void pick_card_from_discard_pile(Player& player);
	int check_for_removable_column(Player& player);
	void remove_column(Player& player, int column_index);
	void discard_card(Player& player, DiscardPile& discard_pile);
	/**
	 * @brief Discards the top card of the draw pile.
	 */
	void discard_draw_pile_top_card();


private:
	Application& m_application;
	unsigned int m_player_amount;

	std::vector<Player> m_players;

	std::vector<Card> m_cards;
	std::vector<Card> build_cards_vector();

	DrawPile m_draw_pile;
	DiscardPile m_discard_pile;
};


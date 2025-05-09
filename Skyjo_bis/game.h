#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "card.h"
#include "player.h"
#include "draw_pile.h"
#include "discard_pile.h"
#include "constants.h"
#include "user_input_handler.h"
//#define GAME_DEBUG true

class Application;

class Game
{
public:
	Game(Application& application, unsigned int player_amount) : m_application(application), m_player_amount(player_amount), m_discard_pile(this, {})
	{
		#ifdef GAME_DEBUG
			std::cout << "Game created at address: " << this << std::endl;
		#endif // GAME_DEBUG

		m_players = build_players_vector();

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
	inline UserInputHandler& get_user_input_handler() { return m_user_input_handler; }
	inline int get_score(Player& player) const { return player.get_score(); }

	void shuffle_cards();
	void distribute_cards();
	void reveal_card(Player& player, size_t deck_index);
	void pick_card_from_draw_pile(Player& player);
	void pick_card_from_discard_pile(Player& player);
	int check_for_removable_column(Player& player);
	void remove_column(Player& player, int column_index);
	void discard_card(Player& player, DiscardPile& discard_pile);
	/**
	 * @brief Discards the top card of the draw pile.
	 */
	void discard_draw_pile_top_card();
	/**
	 * @brief Designates the first player to play.
	 */
	Player* designate_first_player();
	/**
	 * @brief Checks if the game is over. A game is over if every cards are visible in every decks.
	 * @return true if the game is over, false otherwise.
	 */
	bool check_game_over() const;
	/**
	 * @brief Returns the next player in the game.
	 * @param player 
	 */
	Player* next_player(Player& player);
	void play_turn(Player& player, bool a_player_has_revealed_all_cards);
	/**
	 * @brief Starts the game loop.
	 */
	void game_loop();

private:
	Application& m_application;
	unsigned int m_player_amount;

	std::vector<Player> m_players;
	std::vector<Player> build_players_vector() const;

	std::vector<Card> m_cards;
	std::vector<Card> build_cards_vector();

	DrawPile m_draw_pile;
	DiscardPile m_discard_pile;

	UserInputHandler m_user_input_handler;
};


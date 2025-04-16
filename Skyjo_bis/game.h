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

	void shuffle_cards();

private:
	Application& m_application;
	unsigned int m_player_amount;

	std::vector<Player> m_players;

	std::vector<Card> m_cards;
	std::vector<Card> build_cards_vector();

	DrawPile m_draw_pile;
	DiscardPile m_discard_pile;


};


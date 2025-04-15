#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "card.h"
#include "constants.h"
#define GAME_DEBUG true

class Application;

class Game
{
public:
	Game(Application& application, unsigned int player_amount) : m_application(application), m_player_amount(player_amount)
	{
		#ifdef GAME_DEBUG
					std::cout << "Game created at address: " << this << std::endl;
		#endif // GAME_DEBUG
		initialize_cards_vector();
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

private:
	Application& m_application;
	unsigned int m_player_amount;

	std::vector<Card> m_cards;
	void initialize_cards_vector();
};


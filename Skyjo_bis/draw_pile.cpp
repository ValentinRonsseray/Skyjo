#include "draw_pile.h"
#include <random>

void DrawPile::shuffle_cards()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
}
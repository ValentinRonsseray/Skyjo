#pragma once  
#include "pile.h"  
class DrawPile :  
   public Pile  
{  
public:
   DrawPile() : Pile(nullptr, {}) {}
   DrawPile(Game* game, std::vector<Card*> cards) : Pile(game, cards) {}

   inline std::vector<Card*> get_cards() const { return m_cards; }
   void shuffle_cards();
};

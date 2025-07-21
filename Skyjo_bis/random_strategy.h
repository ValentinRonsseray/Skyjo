#pragma once
#include "strategy.h"
#include "deck.h"
class RandomStrategy : public Strategy
{
public:
    size_t choose_card_to_replace(Deck player_deck) const override;
    size_t choose_card_to_reveal(Deck player_deck) const override;
    DrawCardSourceEnum choose_where_to_draw() const override;
    CardDecisionEnum choose_discard_or_replace() const override;
};
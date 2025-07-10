#pragma once
#include "strategy.h"
class HumanStrategy : public Strategy
{
public:
    size_t choose_card_to_replace() const override;
    size_t choose_card_to_reveal() const override;
    DrawCardSourceEnum choose_where_to_draw() const override;
    CardDecisionEnum choose_discard_or_replace() const override;
};


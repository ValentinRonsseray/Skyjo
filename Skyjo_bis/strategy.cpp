#include "strategy.h"
#include "human_strategy.h"
#include "random_strategy.h"

std::unique_ptr<Strategy> Strategy::create_strategy(StrategyType strategy_type)
{
	switch (strategy_type)
	{
	case StrategyType::HUMAN_STRATEGY:
		return std::make_unique<HumanStrategy>();
	case StrategyType::RANDOM_STRATEGY:
		return std::make_unique<RandomStrategy>();
	default:
		throw std::invalid_argument("Unknown strategy type");
	}
}

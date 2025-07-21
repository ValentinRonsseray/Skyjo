#include "utils.h"

namespace Utils
{
	int random_integer(int min, int max)
	{
		if (min > max)
			throw std::invalid_argument("Min cannot be greater than max.");
		if (min == max)
			return min;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(min, max);
		return dis(gen);
	}
	
	int random_integer(int max)
	{
		if (max < 0)
			throw std::invalid_argument("Max cannot be negative.");
		return random_integer(0, max);
	}
}


#pragma once
#include <vector>
#include <random>

namespace Utils
{
	template<typename T>
	void shuffle_vector(std::vector<T>& vec)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::shuffle(vec.begin(), vec.end(), gen);
	}

	template<typename T>
    T& pick_random_element_in_vector(std::vector<T>& elements)
    {
        if (elements.empty())
            throw std::runtime_error("Vector is empty.");

        std::random_device rd;
        std::mt19937 gen(rd());

        // Use the vector's own size_type to avoid narrowing
        using size_type = typename std::vector<T>::size_type;
        std::uniform_int_distribution<size_type> dis(
            0,
            static_cast<size_type>(elements.size() - 1)
        );

        size_type index = dis(gen);
        return elements[index];
    }

	/**
	 * @brief Returns a random integer between min and max (inclusive).
	 * @param min The minimum value (inclusive).
	 * @param max The maximum value (inclusive).
	 * @return A random integer between min and max.
	 */
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

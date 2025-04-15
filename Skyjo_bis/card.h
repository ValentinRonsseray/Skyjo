#pragma once



class Card
{
public:
    Card(int points) : m_points(points) {}
    ~Card() = default;

    Card(const Card&) = default;
private:
	int m_points;
};


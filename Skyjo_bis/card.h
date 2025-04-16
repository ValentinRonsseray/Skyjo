#pragma once



class Card
{
public:
    Card(int points) : m_points(points) {}
    Card(const Card&) = default;
    ~Card() = default;

     
private:
	int m_points;
};


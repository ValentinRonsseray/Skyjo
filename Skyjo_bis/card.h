#pragma once



class Card
{
public:
    Card(int points) : m_points(points) {}
    Card(const Card&) = default;
    ~Card() = default;

	inline int get_points() const { return m_points; }
     
private:
	int m_points;
};


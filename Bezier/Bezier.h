#pragma once
#include <vector>
#include <math.h>

#include <SFML/Graphics.hpp>

class Bezier
{
public:
	void update();
	void draw(sf::RenderWindow&) const;
	void setPoint(const unsigned int&, const sf::Vector2f);

protected:
	Bezier(const std::vector<sf::Vector2f>& points);
	virtual void calculate(const float&, sf::Vector2f&)=0;

protected:
	std::vector<sf::Vertex> vertices;
	std::vector<sf::Vector2f> points;
};

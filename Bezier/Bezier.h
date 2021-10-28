#pragma once
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "Point.h"

class Bezier
{
public:
	void mouseButtonPressed(bool, const sf::Vector2i&);
	void update(const sf::Vector2i&);
	void draw(sf::RenderWindow&);

protected:
	Bezier(const std::vector<sf::Vector2f>& points);
	virtual void calculate(const float&, sf::Vector2f&)=0;
	virtual void drawConnections(sf::RenderWindow&)=0;

protected:
	std::vector<sf::Vertex> vertices;
	std::vector<Point> points;
};

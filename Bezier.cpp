#include "Bezier.h"

Bezier::Bezier(const std::vector<sf::Vector2f>& points)
	: vertices(1000)
{
	for (sf::Vector2f point : points)
		this->points.push_back(point);
}

void Bezier::update()
{
	float t;
	for (int iteration = 0; iteration < vertices.size(); ++iteration)
	{
		t = (float)iteration / vertices.size();
		calculate(t, vertices[iteration].position);
	}
}

void Bezier::draw(sf::RenderWindow& window) const
{
	window.draw(&vertices[0], vertices.size(), sf::LineStrip);
}

void Bezier::setPoint(const unsigned int& index, const sf::Vector2f point)
{ points[index] = point; }

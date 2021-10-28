#include "Bezier.h"

Bezier::Bezier(const std::vector<sf::Vector2f>& points)
	: vertices(1000)
{
	for (sf::Vector2f pointCoords : points)
		this->points.push_back(Point(pointCoords));
}

void Bezier::mouseButtonPressed(bool pressed, const sf::Vector2i& mousePos)
{
	for (Point& point : points)
		point.mouseButtonPressed(pressed, mousePos);
}


void Bezier::update(const sf::Vector2i& mousePos)
{
	for (Point& point : points)
		point.update(mousePos);

	float t;
	for (int iteration = 0; iteration < vertices.size(); ++iteration)
	{
		t = (float)iteration / vertices.size();
		calculate(t, vertices[iteration].position);
	}
}

void Bezier::draw(sf::RenderWindow& window)
{	
	drawConnections(window);
	window.draw(&vertices[0], vertices.size(), sf::LineStrip);
	for (const Point& point : points)
		window.draw(point.getShape());
}

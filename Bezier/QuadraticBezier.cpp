#include "QuadraticBezier.h"

QuadraticBezier::QuadraticBezier(const std::vector<sf::Vector2f>& points)
	: Bezier(points)
	, connection(sf::LineStrip, 3)
{
	if (points.size() != 3)
		throw -1;

	for (int i = 0; i < 3; ++i)
		connection[i].color = sf::Color::Blue;
}

void QuadraticBezier::calculate(const float& t, sf::Vector2f& finalPoint)
{
	finalPoint.x =  pow(1 - t, 2) * points[0].getX() +
					(1 - t) * 2 * t * points[1].getX() +
					t * t * points[2].getX();
	finalPoint.y = 	pow(1 - t, 2) * points[0].getY() +
					(1 - t) * 2 * t * points[1].getY() +
					t * t * points[2].getY();
}

void QuadraticBezier::drawConnections(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; ++i)
		connection[i].position = sf::Vector2f(points[i].getX(), 
						points[i].getY());
	window.draw(connection);
}

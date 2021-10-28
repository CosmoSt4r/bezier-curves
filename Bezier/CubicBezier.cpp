#include "CubicBezier.h"

CubicBezier::CubicBezier(const std::vector<sf::Vector2f>& points)
	: Bezier(points)
	, connection(sf::Lines, 4)
{
	if (points.size() != 4)
		throw -1;

	for (int i = 0; i < 4; ++i)
		connection[i].color = sf::Color::Blue;
}

void CubicBezier::calculate(const float& t, sf::Vector2f& finalPoint)
{
	finalPoint.x = 	pow(1 - t, 3) * points[0].getX() +
					pow(1 - t, 2) * 3 * t * points[1].getX() +
					(1 - t) * 3 * pow(t, 2) * points[2].getX() +
					pow(t, 3) * points[3].getX();
	finalPoint.y = 	pow(1 - t, 3) * points[0].getY() +
					pow(1 - t, 2) * 3 * t * points[1].getY() +
					(1 - t) * 3 * pow(t, 2) * points[2].getY() +
					pow(t, 3) * points[3].getY();
}


void CubicBezier::drawConnections(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; ++i)
		connection[i].position = sf::Vector2f(points[i].getX(), 
						points[i].getY());
	window.draw(connection);
}

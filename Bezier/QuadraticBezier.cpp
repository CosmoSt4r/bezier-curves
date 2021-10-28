#include "QuadraticBezier.h"

QuadraticBezier::QuadraticBezier(const std::vector<sf::Vector2f>& points)
	: Bezier(points)
{
	if (points.size() != 3)
		throw -1;
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

#include "CubicBezier.h"

CubicBezier::CubicBezier(const std::vector<sf::Vector2f>& points)
	: Bezier(points)
{
	if (points.size() != 4)
		throw -1;
}

void CubicBezier::calculate(const float& t, sf::Vector2f& finalPoint)
{
	finalPoint.x = 	pow(1 - t, 3) * points[0].x +
					pow(1 - t, 2) * 3 * t * points[1].x +
					(1 - t) * 3 * pow(t, 2) * points[2].x +
					pow(t, 3) * points[3].x;
	finalPoint.y = 	pow(1 - t, 3) * points[0].y +
					pow(1 - t, 2) * 3 * t * points[1].y +
					(1 - t) * 3 * pow(t, 2) * points[2].y +
					pow(t, 3) * points[3].y;
}

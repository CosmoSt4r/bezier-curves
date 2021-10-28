#pragma once
#include "Bezier.h"

class CubicBezier : public Bezier
{
public:
	CubicBezier(const std::vector<sf::Vector2f>&);

private:
	void calculate(const float&, sf::Vector2f&) override;
};

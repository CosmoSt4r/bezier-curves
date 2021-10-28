#pragma once
#include "Bezier.h"

class QuadraticBezier : public Bezier
{
public:
	QuadraticBezier(const std::vector<sf::Vector2f>&);

private:
	void calculate(const float&, sf::Vector2f&) override;
};

#pragma once
#include "Bezier.h"

class CubicBezier : public Bezier
{
public:
	CubicBezier(const std::vector<sf::Vector2f>&);
	void drawConnections(sf::RenderWindow&);

private:
	void calculate(const float&, sf::Vector2f&) override;
	sf::VertexArray connection;
};

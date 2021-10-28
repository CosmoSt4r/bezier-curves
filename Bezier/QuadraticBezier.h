#pragma once
#include "Bezier.h"

class QuadraticBezier : public Bezier
{
public:
	QuadraticBezier(const std::vector<sf::Vector2f>&);
	void drawConnections(sf::RenderWindow&) override;
private:
	void calculate(const float&, sf::Vector2f&) override;
	sf::VertexArray connection;
};

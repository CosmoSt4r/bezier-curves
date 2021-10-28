#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

#include "QuadraticBezier.h"
#include "CubicBezier.h"

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow window;
	sf::Time timePerFrame;
	sf::Color backgroundColor;
	sf::Vector2i mousePos;

	CubicBezier curve;
};

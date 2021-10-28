#include "Game.h"

Game::Game()
	: window(sf::VideoMode(800, 600), "Bezier curves")
{
	/* ---Constructor---
	 * Set time per frame to 1/60 second (60 FPS) 
	 * Set blue background */
	timePerFrame = sf::seconds(1.f / 60.f);
	backgroundColor = sf::Color(0, 26, 51);

	QuadraticBezier* curve1 = new QuadraticBezier({
		sf::Vector2f(10, 10),
		sf::Vector2f(30, 30),
		sf::Vector2f(50, 10),
	});
	curves.push_back(curve1);

	CubicBezier* curve = new CubicBezier({
		sf::Vector2f(100, 100),
		sf::Vector2f(300, 300),
		sf::Vector2f(500, 100),
		sf::Vector2f(700, 300)
	});
	curves.push_back(curve);
}

void Game::run()
{
	/* Main game cycle */

	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;

	while (window.isOpen())
	{
		deltaTime += clock.restart();

		while (deltaTime > timePerFrame)
		{
			deltaTime -= timePerFrame;
			processEvents();
			update();
		}
		render();
	}
}

void Game::processEvents()
{
	mousePos = sf::Mouse::getPosition(window);

	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				break;
			case sf::Event::KeyReleased:
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
					for (Bezier* curve : curves)
						curve->mouseButtonPressed(true, mousePos);
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
					for (Bezier* curve : curves)
						curve->mouseButtonPressed(false, mousePos);
				break;
			case sf::Event::Closed:
				window.close();
				break;
		}
	}
}

void Game::update()
{
	for (Bezier* curve : curves)
		curve->update(mousePos);
}

void Game::render()
{
	window.clear(backgroundColor);
	for (Bezier* curve : curves)
		curve->draw(window);
	window.display();
}

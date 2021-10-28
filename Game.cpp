#include "Game.h"

Game::Game()
	: window(sf::VideoMode(800, 600), "Bezier curves")
	, curve({sf::Vector2f(0, 0), 
			sf::Vector2f(300, 300),
			sf::Vector2f(600, 0),
			sf::Vector2f(800, 100)})
{
	/* ---Constructor---
	 * Set time per frame to 1/60 second (60 FPS) 
	 * Set blue background */
	timePerFrame = sf::seconds(1.f / 60.f);
	backgroundColor = sf::Color(0, 26, 51);
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
				break;
			case sf::Event::MouseButtonReleased:
				break;
			case sf::Event::Closed:
				window.close();
				break;
		}
	}
}

void Game::update()
{
	curve.update();
}

void Game::render()
{
	window.clear(backgroundColor);
	curve.draw(window);
	window.display();
}

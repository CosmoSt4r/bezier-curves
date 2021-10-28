#pragma once
#include <SFML/Graphics.hpp>

class Point
{
public:
	Point(const sf::Vector2f&);
	Point(const float&, const float&);

	const sf::CircleShape& getShape() const;
	void mouseButtonPressed(bool, const sf::Vector2i&);
	void update(const sf::Vector2i&);

	float getX() const noexcept;
	float getY() const noexcept;
private:
	float radius;
	sf::Color inColor, outColor;
	sf::CircleShape shape;
	bool isMoving;
};

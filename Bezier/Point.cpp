#include "Point.h"

Point::Point(const sf::Vector2f& position)
{
	radius = 5.f;
	inColor = sf::Color::Black;
	outColor = sf::Color(242, 242, 242);
	isMoving = false;

	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	shape.setFillColor(inColor);
	shape.setOutlineThickness(radius / 5);
	shape.setOutlineColor(outColor);
	shape.setPosition(position);
}

Point::Point(const float& x, const float& y) 
	: Point(sf::Vector2f(x, y))
{ }

const sf::CircleShape& Point::getShape() const
{ return shape; }

void Point::mouseButtonPressed(bool pressed, const sf::Vector2i& mousePos)
{
	if (pressed && shape.getGlobalBounds().contains(mousePos.x, mousePos.y))
		isMoving = true;
	if (!pressed && isMoving)
		isMoving = false;
}

void Point::update(const sf::Vector2i& mousePos)
{
	if (isMoving)
		shape.setPosition(sf::Vector2f(mousePos.x, mousePos.y));
}

float Point::getX() const noexcept
{ return shape.getPosition().x; }

float Point::getY() const noexcept
{ return shape.getPosition().y; }

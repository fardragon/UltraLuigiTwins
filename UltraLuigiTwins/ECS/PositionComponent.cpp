#include "PositionComponent.h"



PositionComponent::PositionComponent(): posX(0),posY(0)
{
}

unsigned int PositionComponent::x() const
{
	return posX;
}

unsigned int PositionComponent::y() const
{
	return posY;
}

void PositionComponent::setPos(unsigned int x, unsigned int y)
{
	posX = x;
	posY = y;
}

void PositionComponent::setX(unsigned int x)
{
	posX = x;
}

void PositionComponent::setY(unsigned int y)
{
	posY = y;
}

void PositionComponent::update()
{
}

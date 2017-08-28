#include "Entity.h"

Entity::Entity() : m_alive(true)
{
}


Entity::~Entity()
{
}

bool Entity::isAlive() const
{
	return m_alive;
}

void Entity::destroy()
{
	m_alive = false;
}

void Entity::update()
{
	for (auto &it : m_components)
	{
		it->update();
	}
}

void Entity::draw()
{
	for (auto &it : m_components)
	{
		it->draw();
	}
}

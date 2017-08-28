#include "EntityManager.h"



EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

void EntityManager::update()
{
	for (auto &ent : m_entities)
	{
		ent->update();
	}
}

void EntityManager::draw()
{
	for (auto &ent : m_entities)
	{
		ent->draw();
	}
}

void EntityManager::clean()
{
	m_entities.erase
	(
		std::remove_if(std::begin(m_entities), std::end(m_entities), 
			[](const std::unique_ptr<Entity> &ent)->bool {return !ent->isAlive(); })
		, std::end(m_entities)
	);
}

Entity & EntityManager::addEntity()
{
	m_entities.emplace_back(new Entity());
	return *(m_entities.back().get());
}

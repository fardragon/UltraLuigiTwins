#include "Game.h"



Game::Game()
{
	auto &entity = m_entityManager.addEntity();
	entity.addComponent<PositionComponent>();
	m_doc.parseFromFile("desert.tmx");
}


Game::~Game()
{
}

void Game::start()
{


	while(true)
	{
		m_window.pollEvents();

		m_entityManager.clean();
		m_entityManager.update();
		m_entityManager.draw();
	}
}

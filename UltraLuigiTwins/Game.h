#ifndef Game_h__
#define Game_h__

#include "ECS/EntityManager.h"
#include "Window.h"

class Game
{
public:
	Game();
	~Game();
	void start();

private:
	EntityManager m_entityManager;
	Window m_window;


};
#endif // Game_h__



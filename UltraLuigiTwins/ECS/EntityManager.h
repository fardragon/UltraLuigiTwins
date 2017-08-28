#ifndef Manager_h__
#define Manager_h__

#include <vector>
#include <memory>
#include <algorithm>
#include "Entity.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();
	void update();
	void draw();
	void clean();
	Entity& addEntity();

private:
	std::vector<std::unique_ptr<Entity>> m_entities;

};
#endif // Manager_h__


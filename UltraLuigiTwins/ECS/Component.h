#ifndef Component_h__
#define Component_h__
#include <iostream>


using ComponentID = std::size_t;

namespace getCompID
{
	inline ComponentID getUniqueComponentID() noexcept
	{

		static ComponentID lastID = 0u;
		return lastID++;
	}
}

template <class T>
inline ComponentID getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value,"T must inherit from Component");
	static ComponentID TypeID = getCompID::getUniqueComponentID();
	return TypeID;
}


class Entity;
class Component
{
public:
	Component();
	virtual void update() = 0;
	virtual void draw() {};
	virtual void init() {};
	virtual ~Component() = default;

public:
	Entity *m_owner;
	


};

#endif // Component_h__

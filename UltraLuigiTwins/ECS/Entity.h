#ifndef Entity_h__
#define Entity_h__

#include <vector>
#include <memory>
#include <array>
#include <bitset>
#include <type_traits>
#include <cassert>

#include "Component.h"
#include "PositionComponent.h"

constexpr std::size_t maxComponents = 32u;

class Entity
{
public:
	Entity();
	~Entity();

	bool isAlive() const;
	void destroy();
	void update();
	void draw();
	template<class T, class... TArgs> void addComponent(TArgs&&... mArgs);
	template<class T> bool hasComponent() const;
	template<class T> T* getComponent() const;


private:
	bool m_alive;
	std::vector<std::unique_ptr<Component>> m_components;
	std::array<Component*, maxComponents> m_components_array;
	std::bitset<maxComponents> m_components_bitset;



};

template<class T, class...TArgs>
void Entity::addComponent(TArgs&&... mArgs)
{
	assert(!this->hasComponent<T>());

	T* comp(new T(std::forward<TArgs>(mArgs)...));
	comp->m_owner = this;
	m_components.emplace_back(comp);
	m_components_array[getComponentTypeID<T>()] = comp;
	m_components_bitset[getComponentTypeID<T>()] = true;
	comp->init();
}

template <class T>
bool Entity::hasComponent() const
{
	static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
	return m_components_bitset[getComponentTypeID<T>()];
}

template<class T>
T* Entity::getComponent() const
{
	assert(this->hasComponent<T>());
	auto ptr = m_components_array[getComponentTypeID<T>()];
	return static_cast<T*>(ptr);
}

#endif // Entity_h__


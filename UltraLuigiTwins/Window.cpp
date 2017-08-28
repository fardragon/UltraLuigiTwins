#include "Window.h"



Window::Window()
{
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "test");
}


Window::~Window()
{
}

std::vector<sf::Event> Window::pollEvents()
{
	std::vector<sf::Event> events;
	sf::Event current_event;
	while (m_window->pollEvent(current_event))
	{
		events.push_back(current_event);
	}
	return events;
}

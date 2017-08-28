#ifndef Window_h__
#define Window_h__

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Window
{
public:
	Window();
	~Window();
	std::vector<sf::Event> pollEvents();

private:
	std::unique_ptr<sf::RenderWindow> m_window;

};
#endif // Window_h__


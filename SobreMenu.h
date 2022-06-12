#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class SobreMenu
{
private:
	int pos;
	bool MSactive;

	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;
	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;

	void set_values();
	void draw_all();


public:
	sf::RenderWindow* window;
	SobreMenu();
	~SobreMenu();
	bool returnState() { return MSactive; }
	void run_menu();
	void close_menu();

};

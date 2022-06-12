#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ComoMenu
{
private:
	int pos;
	bool MCactive;
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
	ComoMenu();
	~ComoMenu();
	bool returnState() { return MCactive; }
	void run_menu();
	void close_menu();

};

#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class RankingMenu
{
private:
	int pos;
	bool MRactive;

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
	RankingMenu();
	~RankingMenu();
	bool returnState() { return MRactive; }
	void run_menu();
	void close_menu();

};

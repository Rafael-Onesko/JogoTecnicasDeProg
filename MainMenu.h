#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MainMenu 
{
private:
	int pos;
	bool pressed, theselect, MMactive;

	//sf::RenderWindow* window;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;

	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_coord;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;

	void set_values();
	//void loop_events();
	void draw_all();


public:
	sf::RenderWindow* window;
	MainMenu();
	~MainMenu();
	int returnPos() { return pos; }
	bool returnState() { return MMactive; }
	void run_menu();
	void moveUp();
	void moveDown();
	void close_menu();

};

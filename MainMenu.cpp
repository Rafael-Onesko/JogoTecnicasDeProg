#pragma once
#include "MainMenu.h"
#include <SFML/Graphics.hpp>
MainMenu::MainMenu() {
	window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	set_values();
}

MainMenu::~MainMenu()
{
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete bg;
}


void MainMenu::set_values()
{
	window->create(sf::VideoMode(800, 750), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
	window->setPosition(sf::Vector2i(0, 0));
	pos = 0;
	pressed = theselect = false;
	font->loadFromFile("./Data/Alkhemikal.ttf");
	if (!font->loadFromFile("./Data/Alkhemikal.ttf")) 
	{
		std::cout << "Erro na fonte" << std::endl;
	}
	image->loadFromFile("./Data/ImagemMenu.jpg");
	if (!image->loadFromFile("./Data/ImagemMenu.jpg")) {
		std::cout << "Erro na imagem" << std::endl;
	}

	bg->setTexture(*image);
	pos_mouse = { 0,0 };
	mouse_coord = { 0,0 };

	options = { "Caçadores de Monstros", "Jogar", "Opções","Sobre", "Sair"};
	texts.resize(5);
	coords = {{200,40},{350,100},{350,140},{350,180},{350,220} };
	sizes = { 40,28,24,24,24 };
	for (std::size_t i{}; i < texts.size(); i++) 
	{
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::White);
		texts[i].setPosition(coords[i]);
	}
	texts[1].setOutlineThickness(4);
	texts[1].setOutlineColor(sf::Color::Red);
	pos = 1;

}

void MainMenu::loop_events()
{
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (pos < 4)
				++pos;
			pressed = true;
			theselect = false;
			texts[pos].setOutlineThickness(4);
			texts[pos].setOutlineColor(sf::Color::Red);
			texts[pos-1].setOutlineThickness(0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (pos > 1)
				--pos;
			pressed = true;
			theselect = false;
			texts[pos].setOutlineThickness(4);
			texts[pos].setOutlineColor(sf::Color::Red);
			texts[pos + 1].setOutlineThickness(0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&& !theselect) {
			theselect = true;
			std::cout << options[pos]<<"\n";
			if (pos == 4) {
				window->close();
			}
		}


	}

}

void MainMenu::draw_all()
{
	window->clear();
	window->draw(*bg);
	for (auto t : texts) {
		window->draw(t);
	}
	window->display();
}
void MainMenu::run_menu()
{
	while (window->isOpen())
	{
		loop_events();
		draw_all();
	}
}
//virtual void executar(float dt) = 0;
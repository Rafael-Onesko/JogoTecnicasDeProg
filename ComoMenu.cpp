#pragma once
#include "ComoMenu.h"
#include <SFML/Graphics.hpp>
ComoMenu::ComoMenu() {
	window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	set_values();
}

ComoMenu::~ComoMenu()
{
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void ComoMenu::set_values()
{
	window->create(sf::VideoMode(800, 750), "C SFML", sf::Style::Titlebar | sf::Style::Close);
	window->setPosition(sf::Vector2i(0, 0));
	pos = 0;
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
	options = { "Caçadores de Monstros", "Como Jogar:", "Jogador 1: W, A, S, D","Jogador 2: Setas direcionais","Pule na cabeça dos inimos para neutraliza-los", "Esc para voltar"};
	texts.resize(6);
	coords = { {200,40},{350,100},{150,140},{150,180},{50,220},{250,260} };
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
void ComoMenu::draw_all()
{
	window->clear();
	window->draw(*bg);
	for (auto t : texts) {
		window->draw(t);
	}
	window->display();
}

void ComoMenu::run_menu()
{
	MCactive = true;
	draw_all();
}

void ComoMenu::close_menu() {
	MCactive = false;
	window->close();
}
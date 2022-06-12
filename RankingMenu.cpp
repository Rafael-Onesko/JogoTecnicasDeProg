#pragma once
#include "RankingMenu.h"
#include <SFML/Graphics.hpp>
RankingMenu::RankingMenu() {
	window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	set_values();
}

RankingMenu::~RankingMenu()
{
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void RankingMenu::set_values()
{
	window->create(sf::VideoMode(800, 750), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
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
	options = { "Caçadores de Monstros", "Feito Por:", "Thais Say de Carvalho e Rafael Guilherme Onesko","Disciplina: Tecnicas de Programação, ministrada pelo professor: Jean Simao", "Esc para voltar" };
	texts.resize(5);
	coords = { {200,40},{350,100},{150,140},{50,180},{250,220} };
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
void RankingMenu::draw_all()
{
	window->clear();
	window->draw(*bg);
	for (auto t : texts) {
		window->draw(t);
	}
	window->display();
}

void RankingMenu::run_menu()
{
	MRactive = true;
	draw_all();
}

void RankingMenu::close_menu() {
	MRactive = false;
	window->close();
}
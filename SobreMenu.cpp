#pragma once
#include "SobreMenu.h"
#include <SFML/Graphics.hpp>
SobreMenu::SobreMenu() {
	window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	set_values();
}

SobreMenu::~SobreMenu()
{
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void SobreMenu::set_values()
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
	options = { "Ca�adores de Monstros", "Feito Por:", "Thais Say de Carvalho e Rafael Guilherme Onesko","Disciplina: Tecnicas de Programa��o, ministrada pelo professor: Jean Simao", "Esc para voltar" };
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
void SobreMenu::draw_all()
{
	window->clear();
	window->draw(*bg);
	for (auto t : texts) {
		window->draw(t);
	}
	window->display();
}

void SobreMenu::run_menu()
{
	MSactive = true;
	draw_all();
}

void SobreMenu::close_menu() {
	MSactive = false;
	window->close();
}
#include "Menu.h"
#include "Jogo.h"
#include <iostream>
Menu::Menu():Ente(menu) {

	font = new sf::Font();
	bg = new sf::RectangleShape(sf::Vector2f((float)Jogo::getGerenciadorGrafico()->getAlturaJanela(), (float)Jogo::getGerenciadorGrafico()->getlarguraJanela()));
	
	set_values();
}

Menu::~Menu()
{

	if(font)
		delete font;
	if(bg)
		delete bg;

	options.clear();
	coords.clear();
	texts.clear();
	sizes.clear();
}


void Menu::set_values()
{
	pos = 0;
	pressed = theselect = false;
	botaoClicado = nenhum;

	if (!font->loadFromFile("./Data/Alkhemikal.ttf"))
	{
		std::cout << "Erro na fonte" << std::endl;
	}
	
	image = Jogo::getGerenciadorGrafico()->carregarTextura("./Data/ImagemMenu.jpg");

	Jogo::getGerenciadorGrafico()->colocaTextura(image,bg);

	options = { "Caçadores de Monstros",  "Um Jogador, Primeira fase", "Dois Jogadores, Primeira fase", 
		"Um Jogador, Segunda fase","Dois Jogadores, Segunda fase" ,"Ranking", "Sair" };

	coords = { {200,40},{250,100},{250,140},{250,180},{250,220},{250,260}, {250,300} };
	sizes = { 40,28,24,24,24,24,24 };
	for (int i = 0; i < 7; i++)
	{
		sf::Text texto;
		texto.setFont(*font);
		texto.setString(options[i]);
		texto.setCharacterSize(sizes[i]);
		texto.setOutlineColor(sf::Color::White);
		texto.setPosition(coords[i]);
		texts.push_back(texto);
	}
	texts[1].setOutlineThickness(4);
	texts[1].setOutlineColor(sf::Color::Red);
	pos = 1;

}

void Menu::loop_events()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (!pressed) {
			if (pos < 6)
				++pos;
			pressed = true;
			theselect = false;
			texts[pos].setOutlineThickness(4);
			texts[pos].setOutlineColor(sf::Color::Red);
			texts[pos - 1].setOutlineThickness(0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (!pressed) {
			if (pos > 1)
				--pos;
			pressed = true;
			theselect = false;
			texts[pos].setOutlineThickness(4);
			texts[pos].setOutlineColor(sf::Color::Red);
			texts[pos + 1].setOutlineThickness(0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		if (options[pos] == "Sair")
			Jogo::getGerenciadorGrafico()->fechaJanela();
		else if (options[pos] == "Um Jogador, Primeira fase")
			botaoClicado = fase1jogador1;
		else if (options[pos] == "Dois Jogadores, Primeira fase")
			botaoClicado = fase1jogador2;
		else if (options[pos] == "Um Jogador, Segunda fase")
			botaoClicado = fase2jogador1;
		else if (options[pos] == "Dois Jogadores, Segunda fase")
			botaoClicado = fase2jogador2;
		theselect = true;
	}
	else {
		pressed = false;
	}




}

void Menu::imprimir_se()
{
	Jogo::getGerenciadorGrafico()->draw(bg);
	for (unsigned int i = 0; i < texts.size(); i++) {
		Jogo::getGerenciadorGrafico()->draw(&texts[i]);
	}
}
void Menu::executar(float dt)
{
	loop_events();
	imprimir_se();
}
botao Menu::getBotaoClicado() const{
	return botaoClicado;
}
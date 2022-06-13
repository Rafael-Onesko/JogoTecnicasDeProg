#include "Menu.h"
#include "Jogo.h"
#include <iostream>
#include <string>
Menu::Menu():Ente(menu) {

	font = new sf::Font();
	bg = new sf::RectangleShape(sf::Vector2f(800.f, 750.f));
	ranking = false;

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
	rankingTexto.clear();
}

void Menu::limpar() {
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

	bg->setPosition(sf::Vector2f(Jogo::getGerenciadorGrafico()->getEsquerdaCamera(),0.f));
	bg->setSize(sf::Vector2f((float)Jogo::getGerenciadorGrafico()->getAlturaJanela(), (float)Jogo::getGerenciadorGrafico()->getlarguraJanela()));

	if (!font->loadFromFile("./Data/Alkhemikal.ttf"))
	{
		std::cout << "Erro na fonte" << std::endl;
	}
	
	image = Jogo::getGerenciadorGrafico()->carregarTextura("./Data/ImagemMenu.jpg");

	Jogo::getGerenciadorGrafico()->colocaTextura(image,bg);

	options = { "Caçadores de Monstros",  "Um Jogador, Primeira fase", "Dois Jogadores, Primeira fase", 
		"Um Jogador, Segunda fase","Dois Jogadores, Segunda fase" ,"Ranking", "Sair" };

	float x = bg->getPosition().x;
	coords = { {200.f + x,40.f},{250.f + x,100.f},{250.f + x,140.f},{250.f + x,180.f},{250.f + x,220.f},{350.f + x,260.f}, {350.f + x,300.f} };
	sizes = { 40,28,24,24,24,24,24 };
	for (unsigned int i = 0; i < sizes.size(); i++)
	{
		sf::Text texto;
		texto.setFont(*font);
		texto.setString(options[i]);
		texto.setCharacterSize(sizes[i]);
		texto.setOutlineColor(sf::Color::White);
		texto.setPosition(coords[i]);
		texts.push_back(texto);
	}
	if (!ranking) {
		pos = 1;
	}
	else {
		pos = 5;
	}
	texts[pos].setOutlineThickness(4);
	texts[pos].setOutlineColor(sf::Color::Red);
}

void Menu::adicionaJogada(int pontuacao, int jogada) {
	if(rankingTexto.size() < 6)
		rankingTexto.push_back("Jogada  " + std::to_string(jogada) + "       " + std::to_string(pontuacao) + " \n");
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
		else if (options[pos] == "Ranking") {
			ranking = true;
			botaoClicado = nenhum;
		}
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

void Menu::addRanking() {

	for (unsigned int i = 0; i < rankingTexto.size(); i++)
	{
		sf::Text texto;
		texto.setFont(*font);
		texto.setString(rankingTexto[i]);
		texto.setCharacterSize(30);
		texto.setOutlineColor(sf::Color::White);
		texto.setPosition(sf::Vector2f(coords[i].x, 350.f + i * 30.f));
		texts.push_back(texto);
	}
}

void Menu::executar(float dt)
{
	Jogo::getGerenciadorGrafico()->ajustarCameraInicio();
	loop_events();
	imprimir_se();
	if (ranking) {
		botaoClicado = nenhum;
		addRanking();
		ranking = false;
	}
}


botao Menu::getBotaoClicado() const{
	return botaoClicado;
}
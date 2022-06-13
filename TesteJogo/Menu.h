#pragma once
#include "Ente.h"
#include <iostream>
#include <vector>
#include <string>
enum botao {
	nenhum = 0,
	fase1jogador1,
	fase1jogador2,
	fase2jogador1,
	fase2jogador2
};
class Menu : public Ente{
private:
	int pos;
	bool pressed, theselect, ranking;

	sf::Font* font;
	sf::Texture* image;
	sf::RectangleShape* bg;

	std::vector<const char*> options;
	std::vector<std::string> rankingTexto;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<int> sizes;

	botao botaoClicado;

public:
	Menu();
	~Menu();
	void executar(float dt);
	void set_values();
	void loop_events();
	void imprimir_se();
	void limpar();
	void adicionaJogada(int pontuacao, int jogada);
	void addRanking();
	botao getBotaoClicado()const;

};


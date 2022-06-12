#pragma once
#include "Ente.h"
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
	bool pressed, theselect;

	sf::Font* font;
	sf::Texture* image;
	sf::RectangleShape* bg;

	std::vector<const char*> options;
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
	botao getBotaoClicado()const;

};


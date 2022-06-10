#include "Plataforma.h"
#include "Jogo.h"
int Plataforma::numPlataformas = 0;
Plataforma::Plataforma() :Obstaculo() {

}
Plataforma::Plataforma(bool cima) : Obstaculo(300.f, 50.f, plataforma) {
	this->setPosX(numPlataformas*300.f);
	if (cima == true) {
		this->setPosY(550.0f);
	}
	else {
		this->setPosY(600.0f);
	}
	numPlataformas++;
	textura = Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Muralha.png");
	setTextura(textura, 0, 0, 1.f, 2.f);
	//corpo->setTexture(Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Grama.png"));
	/*sf::Texture* texplataforma = new sf::Texture;
	texplataforma->loadFromFile("./Assets/Grama.png");*/
}
Plataforma::~Plataforma() {
	numPlataformas--;
}
int Plataforma::getNumPlataformas() {
	return numPlataformas;
}
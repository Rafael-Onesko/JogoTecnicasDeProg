#include "Espinho.h"
#include "Jogo.h"
int Espinho::numEspinhos = 0;
int Espinho::getNumEspinhos() {
	return numEspinhos;
}
Espinho::Espinho(float pX, float pY) :Obstaculo(100.f,50.f,espinho) {
	this->setPosX(pX);
	this->setPosY(pY);
	textura = Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Espinho.png");
	setTextura(textura, textura->getSize().x, 0, -1, 1);
	numEspinhos++;
}
Espinho::Espinho() : Obstaculo() {

}
Espinho::~Espinho() {
	numEspinhos--;
}
#include "Agua.h"
#include "Jogo.h"

int Agua::numAguas = 0;
int Agua::getNumAguas() {
	return numAguas;
}
Agua::Agua(float pX, float pY) :Obstaculo(150.f, 50.f, agua) {
	this->setPosX(pX);
	this ->setPosY(pY);
	textura = Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Agua.png");
	setTextura(textura);
	numAguas++;
}
Agua::Agua() : Obstaculo() {

}
Agua::~Agua() {
	numAguas--;
}
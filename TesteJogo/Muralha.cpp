#include "Muralha.h"
int Muralha::numMuralhas = 0;
int Muralha::getNumMuralhas() {
	return numMuralhas;
}
Muralha::Muralha(float pX, float pY) :Obstaculo(100.f, 200.f, muralha) {
	this->setPosX(pX);
	this->setPosY(pY);
	numMuralhas++;
}
Muralha::Muralha() : Obstaculo() {
	numMuralhas--;
}
Muralha::~Muralha() {

}

#include "Espinho.h"
int Espinho::numEspinhos = 0;
int Espinho::getNumEspinhos() {
	return numEspinhos;
}
Espinho::Espinho(float pX, float pY) :Obstaculo(100.f,50.f,espinho) {
	this->setPosX(pX);
	this->setPosY(pY);
	numEspinhos++;
}
Espinho::Espinho() : Obstaculo() {

}
Espinho::~Espinho() {
	numEspinhos--;
}
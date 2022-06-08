#include "Plataforma.h"
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
}
Plataforma::~Plataforma() {
	numPlataformas--;
}
int Plataforma::getNumPlataformas() {
	return numPlataformas;
}
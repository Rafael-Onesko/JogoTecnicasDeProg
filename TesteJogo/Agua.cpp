#include "Agua.h"
int Agua::numAguas = 0;
int Agua::getNumAguas() {
	return numAguas;
}
Agua::Agua(float pX, float pY) :Obstaculo(150.f, 50.f, agua) {
	this->setPosX(pX);
	this ->setPosY(pY);
	numAguas++;
}
Agua::Agua() : Obstaculo() {

}
Agua::~Agua() {
	numAguas--;
}
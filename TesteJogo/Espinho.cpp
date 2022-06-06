#include "Espinho.h"
Espinho::Espinho(float pX, float pY) :Obstaculo(100.f,50.f,espinho) {
	this->setPosX(pX);
	this->setPosY(pY);
}
Espinho::Espinho() : Obstaculo() {

}
Espinho::~Espinho() {

}
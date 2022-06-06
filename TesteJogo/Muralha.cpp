#include "Muralha.h"
Muralha::Muralha(float pX, float pY) :Obstaculo(100.f, 200.f, muralha) {
	this->setPosX(pX);
	this->setPosY(pY);
}
Muralha::Muralha() : Obstaculo() {

}
Muralha::~Muralha() {

}

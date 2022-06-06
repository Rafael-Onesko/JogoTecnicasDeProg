#include "Agua.h"
Agua::Agua(float pX, float pY) :Obstaculo(100.f, 50.f, agua) {
	this->setPosX(pX);
	this ->setPosY(pY);
}
Agua::Agua() : Obstaculo() {

}
Agua::~Agua() {

}
#include "Personagem.h"

Personagem::Personagem(int id, float tX, float tY,float vel) : Entidade(id, tX, tY) {
	this->velocidade = vel;
}
Personagem::Personagem() : Entidade() {
	this->velocidade = 0;
}
Personagem::~Personagem() {

}
void Personagem::setVelocidade(float vel) {
	this->velocidade = vel;
}
float Personagem::getVelocidade() {
	return this->velocidade;
}

#include "Personagem.h"

Personagem::Personagem(int id, float tX, float tY,float vel) : Entidade(id, tX, tY) {
	this->velocidadeX = vel;
	this->velocidadeY = vel;
}
Personagem::Personagem() : Entidade() {
	this->velocidadeX = 0;
	this->velocidadeY = 0;
	direcaoDireita = false;
	direcaoCima = false;
}
Personagem::~Personagem() {

}
void Personagem::setVelocidadeX(float velX) {
	this->velocidadeX = velX;
}
float Personagem::getVelocidadeX() {
	return this->velocidadeX;
}
void Personagem::setVelocidadeY(float velY) {
	this->velocidadeY = velY;
}
float Personagem::getVelocidadeY() {
	return this->velocidadeY;
}
bool Personagem::getDirecaoDireita(){
	return direcaoDireita;
}
bool Personagem::getDirecaoCima(){
	return direcaoCima;
}


#include "Personagem.h"

Personagem::Personagem(ID id, float tX, float tY,float vel) : Entidade(id, tX, tY) {
	this->velPadrao = vel;
	this->velocidadeX = 0;
	this->velocidadeY = 0;
	vivo = true;
	noChao = false;
}
Personagem::Personagem() : Entidade() {
	this->velPadrao = 0;
	this->velocidadeX = 0;
	this->velocidadeY = 0;
	direcaoDireita = false;
	direcaoCima = false;
	noChao = false;
	vivo = true;
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
	return this->direcaoDireita;
}
bool Personagem::getDirecaoCima(){
	return this->direcaoCima;
}
bool Personagem::getNochao() {
	return this->noChao;
}
bool Personagem::getVivo() {
	return this->vivo;
}
void Personagem::setVivo(bool vivo) {
	this->vivo = vivo;
}
void Personagem::mover() {
	posXant = posX;
	posYant = posY;
	this->setPosX(posX + velocidadeX);
	this->setPosY(posY + velocidadeY);
	if (posX < 0)
		setPosX(0.f);
}


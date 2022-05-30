#include<SFML/Graphics.hpp>
#include "Entidade.h"
Entidade::Entidade():Ente() {
	corpo = NULL;
	tamX = 0;
	tamY = 0;
}
Entidade::Entidade(int id, float tX, float tY):Ente(id) {
	this->tamX = tX;
	this->tamY = tY;
	corpo = new sf::RectangleShape(sf::Vector2f(tX, tY));
	corpo->setFillColor(sf::Color::Blue);
}
Entidade::~Entidade() {
	delete corpo;
}
float Entidade::getTamX() {
	return this->tamX;
}
float Entidade::getTamY() {

	return this->tamY;
}
void Entidade::setTamX(float tX) {
	this->tamX = tX;
	corpo->setSize(sf::Vector2f(this->tamX, this->tamY));
}
void Entidade::setTamY(float tY) {
	this->tamY = tY;
	corpo->setSize(sf::Vector2f(this->tamX, this->tamY));
}
float Entidade::getPosX() {
	return this->posX;
}
float Entidade::getPosY() {

	return this->posY;
}
void Entidade::setPosX(float pX) {
	this->posX = pX;
	corpo->setPosition(sf::Vector2f(posX, posY));
}
void Entidade::setPosY(float pY) {
	this->posY = pY;
	corpo->setPosition(sf::Vector2f(posX, posY));
}
float Entidade::getPosXant() {
	return posXant;
}
float Entidade::getPosYant() {
	return posYant;
}
sf::RectangleShape* Entidade::getCorpo(){
	return corpo;
}
float Entidade::getCentroX() {
	float centroX = posX + tamX / 2.f;
	return centroX;
}
float Entidade::getCentroY() {
	float centroY = posY + tamY / 2.f;
	return centroY;
}
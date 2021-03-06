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
}
void Entidade::setPosY(float pY) {
	this->posY = pY;
}
sf::RectangleShape* Entidade::getCorpo(){
	return corpo;
}

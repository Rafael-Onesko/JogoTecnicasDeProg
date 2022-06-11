#include<SFML/Graphics.hpp>
#include "Entidade.h"
#include "Jogo.h"
namespace Entidades {
	Entidade::Entidade() :Ente() {
		corpo = NULL;
		tamX = 0;
		tamY = 0;
	}
	Entidade::Entidade(ID id, float tX, float tY) : Ente(id) {
		gerenciadorGrafico = Jogo::getGerenciadorGrafico();
		this->tamX = tX;
		this->tamY = tY;
		vivo = true;
		corpo = new sf::RectangleShape(sf::Vector2f(tX, tY));
		if (id == jogador1)
			corpo->setFillColor(sf::Color::Blue);
		else if (id == goblin)
			corpo->setFillColor(sf::Color::Cyan);
		else if (id == vampiro)
			corpo->setFillColor(sf::Color::Green);
		else if (id == dragao)
			corpo->setFillColor(sf::Color::Magenta);
		else if (id == muralha)
			corpo->setFillColor(sf::Color::Red);
		else if (id == espinho)
			corpo->setFillColor(sf::Color::Yellow);
		else if (id == agua)
			corpo->setFillColor(sf::Color::Blue);
	}
	Entidade::~Entidade() {
		if (corpo)
			delete corpo;
		tamX = 0;
		tamY = 0;
		posX = 0;
		posY = 0;
		posXant = 0;
		posYant = 0;
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
	sf::RectangleShape* Entidade::getCorpo() {
		return corpo;
	}
	sf::Texture* Entidade::getTextura() {
		return textura;
	}
	void Entidade::setTextura(sf::Texture* text, int rectX, int rectY, float scaleX, float scaleY) {
		textura = text;
		gerenciadorGrafico->colocaTextura(textura, corpo, rectX, rectY, scaleX, scaleY);
	}
	float Entidade::getCentroX() {
		float centroX = posX + tamX / 2.f;
		return centroX;
	}
	float Entidade::getCentroY() {
		float centroY = posY + tamY / 2.f;
		return centroY;
	}
	float Entidade::getDireita() {
		return (this->posX - tamX);
	}
	bool Entidade::getVivo() {
		return this->vivo;
	}
	void Entidade::imprimir_se() {
		if (gerenciadorGrafico)
			gerenciadorGrafico->draw(this->corpo);
	}
	void Entidade::setVivo(bool viv) {
		this->vivo = viv;
	}
}
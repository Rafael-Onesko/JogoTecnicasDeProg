#include "Barra_Vida.h"
#include "Jogador.h"
Barra_Vida::Barra_Vida(Jogador* jogador):Entidade(barraVida, 100.f, 25.f) {
	this->jogador = jogador;
	setPosX(10.f);
	corpo->setFillColor(sf::Color::Green);
	if (jogador->getId() == jogador2)
		barra2 = true;
	else
		barra2 = false;
}
Barra_Vida::Barra_Vida() : Entidade() {

}
Barra_Vida::~Barra_Vida() {

}
void Barra_Vida::arrumarBarra() {
	setTamX((float) jogador->getVidas());
	setPosX(jogador->getPosX());
	setPosY(jogador->getPosY() - 30.f);
}
void Barra_Vida::executar(float dt) {
	arrumarBarra();
}
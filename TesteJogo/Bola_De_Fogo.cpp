#include "Bola_De_Fogo.h"
Bola_De_Fogo::Bola_De_Fogo():Entidade() {

}
Bola_De_Fogo::Bola_De_Fogo(float pX, float pY, int direcao):Entidade(bolaDeFogo, 50.0f, 50.0f) {
	vivo = true;
	this->setPosY(pY);
	this->setPosX(pX);
	this->direcao = direcao;
	velocidadeX = 1;
	velocidadeY = 0.12f;
}
Bola_De_Fogo::~Bola_De_Fogo(){

} 
void Bola_De_Fogo::mover(float dt) {
	if (velocidadeX != 0 && velocidadeY != 0) {
		velocidadeX = 80.f * direcao * dt;
		velocidadeY += GRAVIDADE * dt * dt;

		this->setPosX(posX + velocidadeX);
		this->setPosY(posY + velocidadeY);
	}
}
void Bola_De_Fogo::colidir(ID IdOutro, float colisaoX, float colisaoY) {
	if (IdOutro == ID::dragao)
		return;
	else {
		vivo = false;
	}
}
void Bola_De_Fogo::executar(float dt){
	mover(dt);
}
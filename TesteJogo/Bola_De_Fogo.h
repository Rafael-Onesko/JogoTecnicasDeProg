#pragma once
#include "Entidade.h"
class Bola_De_Fogo : public Entidade
{
private:
	int direcao;
	float velocidadeX;
	float velocidadeY;
public:
	Bola_De_Fogo(float pX, float pY, int direcao);
	Bola_De_Fogo();
	~Bola_De_Fogo();
	void executar(float dt);
	void mover(float dt);
	void colidir(ID IdOutro, float colisaoX, float colisaoY);
};


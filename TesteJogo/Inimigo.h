#pragma once
#include "Jogador.h"
class Inimigo: public Personagem
{
protected:
	float alcanceMover;
	float andou;
	int direcao;
	Jogador* jogador1;
	Jogador* jogador2;
public:
	Inimigo(float tX, float tY, float vel, ID id, Jogador* jog1, Jogador* jog2);
	Inimigo();
	virtual ~Inimigo();
	virtual void colidir(ID IdOutro, float colisaoX, float colisaoY);
	virtual void receberDano() = 0;
	virtual void ajustarDeslocamento(float dt);
	void setJogador2(Jogador* jog2);
};


#pragma once
#include "Personagem.h"
class Inimigo: public Personagem
{
protected:
public:
	Inimigo(float tX, float tY, float vel);
	Inimigo();
	~Inimigo();
	virtual void colidir(int IdOutro, float colisaoX, float colisaoY);
	void mover();
};


#pragma once
#include "Personagem.h"
class Inimigo: public Personagem
{
protected:
public:
	virtual void colidir(int IdOutro, float colisaoX, float colisaoY);
};


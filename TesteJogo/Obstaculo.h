#pragma once
#include "Entidade.h"
class Obstaculo: public Entidade
{
protected:
public:
	virtual void colidir(int IdOutro, float colisaoX, float colisaoY);
};


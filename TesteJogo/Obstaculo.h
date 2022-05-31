#pragma once
#include "Entidade.h"
class Obstaculo: public Entidade
{
protected:
public:
	Obstaculo(float tX, float tY);
	Obstaculo();
	~Obstaculo();
	virtual void colidir(int IdOutro, float colisaoX, float colisaoY);
};


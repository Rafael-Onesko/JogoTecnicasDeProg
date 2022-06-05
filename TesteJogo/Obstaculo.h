#pragma once
#include "Entidade.h"
class Obstaculo: public Entidade
{
protected:
public:
	Obstaculo(float tX, float tY, ID id);
	Obstaculo();
	virtual ~Obstaculo();
	virtual void colidir(int IdOutro, float colisaoX, float colisaoY);
	virtual void executar(float dt);
};


#pragma once
#include "Entidade.h"
class Personagem : public Entidade
{
protected:
		float velocidade;
public:
	Personagem(int id, float tX, float tY, float vel);
	Personagem();
	~Personagem();
	void setVelocidade(float vel);
	float getVelocidade();

};


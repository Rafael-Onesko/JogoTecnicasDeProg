#pragma once
#include "Entidade.h"
class Personagem : public Entidade
{
protected:
		float velocidadeX;
		float velocidadeY;
		bool direcaoDireita;
		bool direcaoCima;
public:
	Personagem(int id, float tX, float tY, float vel);
	Personagem();
	~Personagem();
	void setVelocidadeX(float velX);
	void setVelocidadeY(float velY);
	float getVelocidadeX();
	float getVelocidadeY();
	bool getDirecaoDireita();
	bool getDirecaoCima();
};


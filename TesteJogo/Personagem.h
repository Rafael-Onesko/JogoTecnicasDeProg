#pragma once
#include "Entidade.h"
class Personagem : public Entidade
{
protected:
		float velocidadeX;
		float velocidadeY;
		float velPadrao;
		bool direcaoDireita;
		bool direcaoCima;
		bool noChao;
		bool vivo;
public:
	Personagem(ID id, float tX, float tY, float vel);
	Personagem();
	virtual ~Personagem();
	void setVelocidadeX(float velX);
	void setVelocidadeY(float velY);
	float getVelocidadeX();
	float getVelocidadeY();
	bool getDirecaoDireita();
	bool getDirecaoCima();
	bool getNochao();
	bool getVivo();
	void setVivo(bool vivo);
	virtual void receberDano() = 0;
	virtual void mover();
	virtual void ajustarDeslocamento(float dt) = 0;
};


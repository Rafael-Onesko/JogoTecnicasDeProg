#pragma once
#include "Entidade.h"
class Jogador;
class Barra_Vida :public Entidade
{
private:
	Jogador* jogador;
	bool barra2;
public:
	Barra_Vida(Jogador* jogador);
	Barra_Vida();
	~Barra_Vida();
	void arrumarBarra();
	void executar(float dt);

};


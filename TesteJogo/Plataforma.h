#pragma once
#include "Obstaculo.h"
class Plataforma : public Obstaculo
{
private:
	static int numPlataformas;
public:
	Plataforma();
	Plataforma(bool cima);
	~Plataforma();
	static int getNumPlataformas();
};


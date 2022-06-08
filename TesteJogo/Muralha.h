#pragma once
#include "Obstaculo.h"
class Muralha :
	public Obstaculo
{
private:
	static int numMuralhas;
public:
	Muralha();
	~Muralha();
	Muralha(float pX, float pY);
	static int getNumMuralhas();
};


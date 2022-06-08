#pragma once
#include "Obstaculo.h"
class Agua : public Obstaculo
{
private:
	static int numAguas;
public:
	Agua();
	Agua(float pX, float pY);
	~Agua();
	static int getNumAguas();
};


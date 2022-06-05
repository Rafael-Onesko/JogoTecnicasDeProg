#pragma once
#include "Inimigo.h"
class Goblin :
	public Inimigo
{
private:
public:
	Goblin();
	~Goblin();
	Goblin(float tX, float tY, Jogador* jog1, Jogador* jog2 = nullptr);
	void receberDano();
	void executar(float dt);
};


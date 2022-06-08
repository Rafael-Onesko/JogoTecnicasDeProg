#pragma once
#include "Inimigo.h"
class Goblin :
	public Inimigo
{
private:
	static int numGoblins;
public:
	Goblin();
	~Goblin();
	Goblin(float pX, float pY, Jogador* jog1, Jogador* jog2 = nullptr);
	void receberDano(int dano = 1);
	void executar(float dt);
	static int getNumGoblins();
};


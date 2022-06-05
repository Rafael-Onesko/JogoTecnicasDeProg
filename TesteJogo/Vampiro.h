#pragma once
#include "Inimigo.h"
class Vampiro :
	public Inimigo
{
private:
	float alcancePerseguir;
	int vidas;
	bool perseguindoJog1;
	bool perseguindoJog2;
	float distanciaJog1;
	float distanciaJog2;
	bool fugindo;
public:
	Vampiro();
	~Vampiro();
	Vampiro(float tX, float tY, Jogador* jog1, Jogador* jog2 = nullptr);
	void receberDano();
	void executar(float dt);
	void perseguir();
	void procuraJogador();
	float getAlcancePerseguir();
	bool getPerseguindoJog1();
	bool getPerseguindoJog2();
	int getVidas();
};


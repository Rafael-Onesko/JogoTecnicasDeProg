#pragma once
#include "Inimigo.h"
#include "Bola_De_Fogo.h"
class Dragao : public Inimigo
{
private:
	float tempoAtaque;
	float tempoAtacando;
	bool atacando;
	bool ataca;
	Bola_De_Fogo* bolaDeFogo;
	int vidas; 
	float alcanceAtacar;
	float distanciaJog1X;
	float distanciaJog2X;
	float distanciaJog1Y;
	float distanciaJog2Y;
	bool fugindo;
public:
	Dragao();
	~Dragao();
	Dragao(Jogador* jog1, Jogador* jog2 = nullptr);
	void receberDano();
	void colidir(ID IdOutro, float colisaoX, float colisaoY);
	void ajustarDeslocamento(float dt);
	void executar(float dt);
	void atacar(float dt);
	void tacarFogo();
	void procuraJogador();
	bool getAtacando();
	float getTempoAtaque();
	int getVidas();
};


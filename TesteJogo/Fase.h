#pragma once
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Goblin.h"
#include "Vampiro.h"
#include "Dragao.h"
#include "Muralha.h"
#include "Espinho.h"
#include "Agua.h"
#include "ListaEntidades.h"
#include "Plataforma.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Fase: public Ente
{
protected:
	vector<string> entidadesGeradas;
	vector<Plataforma*> plataformas;
	int numObstaculos;
	const int numTotalPlataformas;
	Jogador* player1;
	Jogador* player2;
	Gerenciador_Colisoes* gerenciadorColisoes;
	ListaEntidades* entidades;
	float tamanhoFase;
	bool fim;
public:
	Fase();
	~Fase();
	Fase(bool doisJogadores, Gerenciador_Grafico* gerenciGrafc);
	virtual void imprimir_se();
	void executar(float dt);
	void geraEntidades(vector<string>* nomesEntidades);
	void randomizarPosicoes(string entidadeCriar);
	const float  getTamanhoFase() const; 
	bool  getFim() const;
};


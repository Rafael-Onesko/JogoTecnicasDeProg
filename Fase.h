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
namespace Fases {
	class Fase : public Ente
	{
	protected:
		sf::RectangleShape fundo;
		vector<string> entidadesGeradas;
		vector<Entidades::Obstaculos::Plataforma*> plataformas;
		int numObstaculos;
		const int numTotalPlataformas;
		Entidades::Personagens::Jogador* player1;
		Entidades::Personagens::Jogador* player2;
		Gerenciadores::Gerenciador_Colisoes* gerenciadorColisoes;
		Listas::ListaEntidades* entidades;
		float tamanhoFase;
		bool fim;
	public:
		Fase();
		~Fase();
		Fase(bool doisJogadores);
		virtual void imprimir_se();
		void executar(float dt);
		void geraEntidades(vector<string>* nomesEntidades);
		void randomizarPosicoes(string entidadeCriar);
		const float  getTamanhoFase() const;
		bool  getFim() const;
		bool getJogador1Vivo() const;
		bool getJogador2Vivo() const;
		Entidades::Personagens::Jogador* getPlayer1() const;
		Entidades::Personagens::Jogador* getPlayer2() const;
	};
}
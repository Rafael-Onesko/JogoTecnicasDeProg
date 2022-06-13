#pragma once
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Bola_De_Fogo.h"
namespace Entidades {
	namespace Personagens {
		class Dragao : public Inimigo
		{
		private:
			static int numDragaos;
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
			Listas::ListaEntidades* lE;
		public:
			Dragao();
			~Dragao();
			Dragao(float pX, float pY, Listas::ListaEntidades* listEntid, Jogador* jog1, Jogador* jog2 = nullptr);
			void receberDano(int dano = 1);
			void colidir(ID IdOutro, float colisaoX, float colisaoY);
			void ajustarDeslocamento(float dt);
			void executar(float dt);
			void atacar(float dt);
			void tacarFogo();
			void procuraJogador();
			bool getAtacando();
			float getTempoAtaque();
			int getVidas();
			static int getNumDragaos();
		};
	}
}


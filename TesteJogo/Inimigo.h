#pragma once
#include "Jogador.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem
		{
		protected:
			static int numInimigos;
			float alcanceMover;
			float andou;
			int direcao;
			Jogador* jogador1;
			Jogador* jogador2;
		public:
			Inimigo(float tX, float tY, float vel, ID id, Jogador* jog1, Jogador* jog2);
			Inimigo();
			virtual ~Inimigo();
			virtual void colidir(ID IdOutro, float colisaoX, float colisaoY);
			virtual void receberDano(int dano = 1) = 0;
			virtual void ajustarDeslocamento(float dt);
			void setJogador2(Jogador* jog2);
			static int getNumInimigos();
		};
	}
}


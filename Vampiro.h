#pragma once
#include "Inimigo.h"
namespace Entidades {
	namespace Personagens {
		class Vampiro : public Inimigo
		{
		private:
			static int numVampiros;
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
			Vampiro(float pX, float pY, Jogador* jog1, Jogador* jog2 = nullptr);
			void receberDano(int dano = 1);
			void executar(float dt);
			void perseguir();
			void procuraJogador();
			float getAlcancePerseguir();
			bool getPerseguindoJog1();
			bool getPerseguindoJog2();
			int getVidas();
			static int getNumVampiros();
		};
	}
}


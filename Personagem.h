#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			float velocidadeX;
			float velocidadeY;
			float velPadrao;
			bool direcaoDireita;
			bool direcaoCima;
			bool noChao;
		public:
			Personagem(ID id, float tX, float tY, float vel);
			Personagem();
			virtual ~Personagem();
			void setVelocidadeX(float velX);
			void setVelocidadeY(float velY);
			float getVelocidadeX()const;
			float getVelocidadeY()const;
			bool getDirecaoDireita()const;
			bool getDirecaoCima()const;
			bool getNochao()const;
			virtual void receberDano(int dano = 1) = 0;
			virtual void mover();
			virtual void ajustarDeslocamento(float dt) = 0;
		};
	}
}

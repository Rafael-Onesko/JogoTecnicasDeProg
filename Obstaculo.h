#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace Obstaculos {
		class Obstaculo : public Entidade
		{
		protected:
			float velocidadeY;
			bool noChao;
		public:
			Obstaculo(float tX, float tY, ID id);
			Obstaculo();
			virtual ~Obstaculo();
			virtual void colidir(ID IdOutro, float colisaoX, float colisaoY);
			virtual void executar(float dt);
		};
	}
}


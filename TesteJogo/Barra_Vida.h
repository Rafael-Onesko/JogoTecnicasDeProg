#pragma once
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Jogador;
	}
	class Barra_Vida :public Entidade
	{
	private:
		Personagens::Jogador* jogador;
		bool barra2;
	public:
		Barra_Vida(Personagens::Jogador* jogador);
		Barra_Vida();
		~Barra_Vida();
		void arrumarBarra();
		void executar(float dt);
		void colidir(ID IdOutro, float colisaoX, float colisaoY);
	};
}


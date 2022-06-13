#pragma once
#include "ListaEntidades.h"
namespace Gerenciadores {
	class Gerenciador_Colisoes
	{
	private:
		Listas::ListaEntidades* listaEntidades;
	public:
		Gerenciador_Colisoes(Listas::ListaEntidades* listEnt);
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();
		void verificarColisoes();

	};
}


#pragma once
#include "Fase.h"
namespace Fases {
	class Fase_Castelo : public Fase
	{
	private:
	public:
		Fase_Castelo();
		Fase_Castelo(bool doisJogadores, ID idJogador);
		~Fase_Castelo();
	};
}


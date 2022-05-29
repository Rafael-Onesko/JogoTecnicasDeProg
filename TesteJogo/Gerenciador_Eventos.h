#pragma once
#include "Gerenciador_Grafico.h"
class Gerenciador_Eventos
{
private:
		Gerenciador_Grafico* gerenciadorGrafico;
public:
	Gerenciador_Eventos(Gerenciador_Grafico* gerenciadorGrafico);
	Gerenciador_Eventos();
	~Gerenciador_Eventos();
	void pollEvents();
};


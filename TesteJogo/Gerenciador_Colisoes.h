#pragma once
#include "ListaEntidades.h"
class Gerenciador_Colisoes
{
private:
	ListaEntidades* listaEntidades;
public:
	Gerenciador_Colisoes(ListaEntidades* listEnt);
	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();
	void verificarColisoes();

};


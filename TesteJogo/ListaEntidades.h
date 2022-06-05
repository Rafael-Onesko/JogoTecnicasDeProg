#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades {
public:
	ListaEntidades();
	~ListaEntidades();
	Lista<Entidade> lE;
	void inserir(Entidade* entid);
	void retirar(Entidade* entid);
	int getTam();
	Entidade* operator[](int index) {
		return lE[index];
	}
};


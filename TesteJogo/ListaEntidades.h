#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades {
public:
	ListaEntidades();
	~ListaEntidades();
	Lista<Entidade> lE;
	void push(Entidade* entid);
	void pop(Entidade* entid);
	int getTam();
	Entidade* operator[](int index) {
		return lE[index];
	}
};


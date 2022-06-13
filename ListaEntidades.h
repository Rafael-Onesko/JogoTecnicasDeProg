#pragma once
#include "Lista.h"
#include "Entidade.h"
namespace Listas {
	class ListaEntidades {
	public:
		ListaEntidades();
		~ListaEntidades();
		Lista<Entidades::Entidade> lE;
		void inserir(Entidades::Entidade* entid);
		void retirar(Entidades::Entidade* entid);
		int getTam();
		Entidades::Entidade* operator[](int index);
		void operator+=(Entidades::Entidade* entid);
	};
}


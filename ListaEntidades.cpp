#include "ListaEntidades.h"
namespace Listas {
	ListaEntidades::ListaEntidades() :lE() {

	}
	ListaEntidades::~ListaEntidades() {
		lE.limpar();
	}
	void ListaEntidades::inserir(Entidades::Entidade* entid) {
		if (entid)
			lE.inserir(entid);
	}
	void ListaEntidades::retirar(Entidades::Entidade* entid) {
		if (entid)
			lE.retirar(entid);
	}
	int ListaEntidades::getTam() {
		return lE.getTam();
	}
	Entidades::Entidade* ListaEntidades::operator[](int index) {
		return lE[index];
	}
	void ListaEntidades::operator+=(Entidades::Entidade* entid) {
		lE.inserir(entid);
	}
}
#include "ListaEntidades.h"
ListaEntidades::ListaEntidades() {
}
ListaEntidades::~ListaEntidades() {
	lE.limpar();
}
void ListaEntidades::inserir(Entidade* entid) {
	lE.inserir(entid);
}
void ListaEntidades::retirar(Entidade* entid) {
	lE.retirar(entid);
}
int ListaEntidades::getTam() {
	return lE.getTam();
}

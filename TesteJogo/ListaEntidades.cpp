#include "ListaEntidades.h"
ListaEntidades::ListaEntidades():lE() {

}
ListaEntidades::~ListaEntidades() {
	lE.limpar();
}
void ListaEntidades::inserir(Entidade* entid) {
	if(entid)
		lE.inserir(entid);
}
void ListaEntidades::retirar(Entidade* entid) {
	if(entid)
		lE.retirar(entid);
}
int ListaEntidades::getTam() {
	return lE.getTam();
}
Entidade* ListaEntidades::operator[](int index) {
	return lE[index];
}
void ListaEntidades::operator+=(Entidade* entid) {
	lE.inserir( entid );
}

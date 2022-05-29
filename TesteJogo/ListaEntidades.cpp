#include "ListaEntidades.h"
ListaEntidades::ListaEntidades() {
}
ListaEntidades::~ListaEntidades() {

}
void ListaEntidades::push(Entidade* entid) {
	lE.push(entid);
}
void ListaEntidades::pop(Entidade* entid) {
	lE.pop(entid);
}
int ListaEntidades::getTam() {
	return lE.getTam();
}

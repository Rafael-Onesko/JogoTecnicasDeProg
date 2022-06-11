#include "Ente.h"
Ente::Ente(ID id) {
	this->id = id;
	gerenciadorGrafico = nullptr;
}
Ente::~Ente() {
	gerenciadorGrafico = nullptr;
}
void Ente::setId(ID Id) {
	this->id = id;
}
ID Ente::getId() {
	return this->id;
}
void Ente::setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico* gerenciGraf) {
	if(gerenciGraf)
		this->gerenciadorGrafico = gerenciGraf;
}

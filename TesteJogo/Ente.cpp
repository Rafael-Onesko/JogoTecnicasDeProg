#include "Ente.h"
Ente::Ente(int id) {
	this->id = id;
}
Ente::~Ente() {
}
void Ente::setId(int Id) {
	this->id = id;
}
int Ente::getId() {
	return this->id;
}

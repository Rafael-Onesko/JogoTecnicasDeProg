#include "Gerenciador_Colisoes.h"
#include<math.h>
Gerenciador_Colisoes::Gerenciador_Colisoes() {
	listaEntidades= nullptr;
}
Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* listEnt) {
	listaEntidades = listEnt;
}
Gerenciador_Colisoes::~Gerenciador_Colisoes(){
	listaEntidades = nullptr;
}
void Gerenciador_Colisoes::verificarColisoes() {
	float distanciaCentroX;
	float distanciaCentroY;
	float somaTamanhoX;
	float somaTamanhoY;
	Entidade* ent = nullptr;
	Entidade* entOutro = nullptr;
	for (int i = 0; i < listaEntidades->getTam(); i++) {
		for (int j = 0; j < listaEntidades->getTam(); j++) {
			ent = (*listaEntidades)[i];
			entOutro = (*listaEntidades)[j];
			distanciaCentroX = fabs(ent->getCentroX() - entOutro->getCentroX());
			distanciaCentroY = fabs(ent->getCentroY() - entOutro->getCentroY());
			somaTamanhoX = ((ent->getTamX()) / 2.f) + ((entOutro->getTamX()) / 2.f);
			somaTamanhoY = ((ent->getTamX()) / 2.f) + ((entOutro->getTamX()) / 2.f);
			if (distanciaCentroX < somaTamanhoX && distanciaCentroY < somaTamanhoY) {
				ent->colidir(entOutro->getId(), somaTamanhoX - distanciaCentroX, somaTamanhoY - distanciaCentroY);
				entOutro->colidir(ent->getId(), somaTamanhoX - distanciaCentroX, somaTamanhoY - distanciaCentroX);
			}
		}
	}
}


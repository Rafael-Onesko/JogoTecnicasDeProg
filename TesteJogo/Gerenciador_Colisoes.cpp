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
	for (int i = 0; i < (listaEntidades->getTam() - 1); i++) {
		ent = (*listaEntidades)[i];
		entOutro = (*listaEntidades)[i + 1];
		distanciaCentroX = ent->getPosX() - entOutro->getPosX();
		distanciaCentroY = ent->getPosY() - entOutro->getPosY();
		somaTamanhoX = (ent->getTamX()) / 2 + (entOutro->getTamX()) / 2;
		somaTamanhoY = (ent->getTamX()) / 2 + (entOutro->getTamX()) / 2;
		if (fabs(distanciaCentroX) < somaTamanhoX && fabs(distanciaCentroY) < somaTamanhoY) {
			ent->colidir(entOutro->getId(), somaTamanhoX - fabs(distanciaCentroX), somaTamanhoY - fabs(distanciaCentroY));
			entOutro->colidir(ent->getId(), somaTamanhoX - fabs(distanciaCentroX), somaTamanhoY - fabs(distanciaCentroX));
		}
	}
}


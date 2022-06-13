#include "Gerenciador_Colisoes.h"
#include<math.h>
namespace Gerenciadores {
	Gerenciador_Colisoes::Gerenciador_Colisoes() {
		listaEntidades = nullptr;
	}
	Gerenciador_Colisoes::Gerenciador_Colisoes(Listas::ListaEntidades* listEnt) {
		listaEntidades = listEnt;
	}
	Gerenciador_Colisoes::~Gerenciador_Colisoes() {
		listaEntidades = nullptr;
	}
	void Gerenciador_Colisoes::verificarColisoes() {
		float distanciaCentroX;
		float distanciaCentroY;
		float somaTamanhoX;
		float somaTamanhoY;
		Entidades::Entidade* ent = nullptr;
		Entidades::Entidade* entOutro = nullptr;
		for (int i = 0; i < listaEntidades->getTam(); i++) {
			for (int j = i + 1; j < listaEntidades->getTam(); j++) {
				if (i != j) {
					ent = (*listaEntidades)[i];
					entOutro = (*listaEntidades)[j];
					distanciaCentroX = fabs(ent->getCentroX() - entOutro->getCentroX());
					distanciaCentroY = fabs(ent->getCentroY() - entOutro->getCentroY());
					somaTamanhoX = ((ent->getTamX()) / 2.f) + ((entOutro->getTamX()) / 2.f);
					somaTamanhoY = ((ent->getTamY()) / 2.f) + ((entOutro->getTamY()) / 2.f);
					if (distanciaCentroX < somaTamanhoX && distanciaCentroY < somaTamanhoY) {
						ent->colidir(entOutro->getId(), fabs(somaTamanhoX - distanciaCentroX), fabs(somaTamanhoY - distanciaCentroY));
						entOutro->colidir(ent->getId(), fabs(somaTamanhoX - distanciaCentroX), fabs(somaTamanhoY - distanciaCentroY));
					}
				}
			}
		}
	}
}


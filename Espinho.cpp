#include "Espinho.h"
#include "Jogo.h"
namespace Entidades {
	namespace Obstaculos {
		int Espinho::numEspinhos = 0;
		int Espinho::getNumEspinhos() {
			return numEspinhos;
		}
		Espinho::Espinho(float pX, float pY) :Obstaculo(100.f, 50.f, espinho) {
			this->setPosX(pX);
			this->setPosY(pY);
			textura = Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Espinho.png");
			setTextura(textura, 0, textura->getSize().y / 2, 1, 1);
			numEspinhos++;
		}
		Espinho::Espinho() : Obstaculo() {

		}
		Espinho::~Espinho() {
			numEspinhos--;
		}
	}
}
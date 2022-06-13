#include "Muralha.h"
#include "Jogo.h"
namespace Entidades {
	namespace Obstaculos {
		int Muralha::numMuralhas = 0;
		int Muralha::getNumMuralhas() {
			return numMuralhas;
		}
		Muralha::Muralha(float pX, float pY) :Obstaculo(100.f, 200.f, muralha) {
			this->setPosX(pX);
			this->setPosY(pY);
			textura = Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Muralha.png");
			setTextura(textura, textura->getSize().x, 0, -1, 1);
			numMuralhas++;
		}
		Muralha::Muralha() : Obstaculo() {
			numMuralhas--;
		}
		Muralha::~Muralha() {

		}
	}
}

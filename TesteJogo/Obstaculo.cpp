#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo(float tX, float tY, ID id) :Entidade(id, tX, tY) {
			velocidadeY = 0;
			noChao = false;
		}
		Obstaculo::Obstaculo() : Entidade() {

		}
		Obstaculo::~Obstaculo() {

		}
		void Obstaculo::colidir(ID IdOutro, float colisaoX, float colisaoY) {
			if (IdOutro == plataforma || this->id == plataforma) {
				if (!noChao)
					setPosY(posY - colisaoY);
				noChao = true;
				velocidadeY = 0;
			}
		}
		void Obstaculo::executar(float dt) {
			if (noChao == false) {
				velocidadeY += GRAVIDADE * dt;
			}
			else
				velocidadeY = 0;
			setPosY(posY + velocidadeY);
		}
	}
}
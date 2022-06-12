#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		Personagem::Personagem(ID id, float tX, float tY, float vel) : Entidade(id, tX, tY) {
			this->velPadrao = vel;
			this->velocidadeX = 0;
			this->velocidadeY = 0;
			noChao = false;
		}

		Personagem::Personagem() : Entidade() {
			this->velPadrao = 0;
			this->velocidadeX = 0;
			this->velocidadeY = 0;
			direcaoDireita = false;
			direcaoCima = false;
			noChao = false;
		}
		Personagem::~Personagem() {

		}
		void Personagem::setVelocidadeX(float velX) {
			this->velocidadeX = velX;
		}
		float Personagem::getVelocidadeX()const {
			return this->velocidadeX;
		}
		void Personagem::setVelocidadeY(float velY) {
			this->velocidadeY = velY;
		}
		float Personagem::getVelocidadeY()const {
			return this->velocidadeY;
		}
		bool Personagem::getDirecaoDireita()const {
			return this->direcaoDireita;
		}
		bool Personagem::getDirecaoCima()const {
			return this->direcaoCima;
		}
		bool Personagem::getNochao()const {
			return this->noChao;
		}
		void Personagem::mover() {
			posXant = posX;
			posYant = posY;
			this->setPosX(posX + velocidadeX);
			this->setPosY(posY + velocidadeY);
			if (posX < 0)
				setPosX(0.f);
			if (posY > gerenciadorGrafico->getAlturaJanela())
				vivo = false;
			else if (posY < 0.f) {
				setPosY(0.f);
				velocidadeY = 0;
			}
		}
	}
}
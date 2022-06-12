#include "Vampiro.h"
#include "Jogo.h"
namespace Entidades {
	namespace Personagens {
		int Vampiro::numVampiros = 0;
		int Vampiro::getNumVampiros() {
			return numVampiros;
		}
		Vampiro::Vampiro() :Inimigo() {

		}
		Vampiro::~Vampiro() {
			numVampiros--;
		}
		Vampiro::Vampiro(float pX, float pY, Jogador* jog1, Jogador* jog2) :Inimigo(100.f, 100.f, 60.f, vampiro, jog1, jog2) {
			alcancePerseguir = 2 * tamX;
			alcanceMover = 3 * tamX;
			setPosX(pX);
			setPosY(pY);
			vidas = 100;
			perseguindoJog1 = false;
			perseguindoJog2 = false;
			fugindo = false;
			textura = Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Vampiro.png");
			setTextura(textura, 0, 0, 1, 1);
			numVampiros++;
		}
		void Vampiro::receberDano(int dano) {
			fugindo = true;
			vidas--;
			if (vidas < 0)
				vivo = false;
		}
		void Vampiro::procuraJogador() {
			distanciaJog1 = jogador1->getCentroX() - this->getCentroX();
			distanciaJog2 = FLT_MAX;

			if (jogador2)
				distanciaJog2 = jogador2->getCentroX() - this->getCentroX();
			if (fugindo) {
				if (fabs(distanciaJog1) > 2 * tamX && fabs(distanciaJog2) > 2 * tamX)
					fugindo = false;
			}
			else {
				if (fabs(distanciaJog1) < tamX || fabs(distanciaJog2) < tamX) {
					fugindo = true;
					return;
				}
				if (fabs(distanciaJog1) < fabs(distanciaJog2) && fabs(distanciaJog1) <= alcancePerseguir)
					perseguindoJog1 = true;
				else
					perseguindoJog1 = false;

				if (fabs(distanciaJog2) < fabs(distanciaJog1) && fabs(distanciaJog2) <= alcancePerseguir)
					perseguindoJog2 = true;
				else
					perseguindoJog2 = false;
			}
		}
		void Vampiro::executar(float dt) {
			procuraJogador();
			if ((!fugindo) && (perseguindoJog1 || perseguindoJog2))
				perseguir();
			ajustarDeslocamento(dt);
			if (fugindo)
				velocidadeX = 2 * velocidadeX;
			mover();
			if(direcao > 0)
				setTextura(textura, textura->getSize().x, 0, -1, 1);
			else
				setTextura(textura, 0, 0, 1, 1);
		}
		float Vampiro::getAlcancePerseguir() {
			return this->alcancePerseguir;
		}
		bool Vampiro::getPerseguindoJog1() {
			return this->perseguindoJog1;
		}
		bool Vampiro::getPerseguindoJog2() {
			return this->perseguindoJog2;
		}
		void Vampiro::perseguir() {
			if (perseguindoJog1) {
				if (distanciaJog1 < 0) {
					if (direcao == 1) {
						direcao = -1;
						if (andou < alcanceMover)
							andou = alcanceMover - andou;
					}
				}
				else {
					if (direcao == -1) {
						direcao = 1;
						if (andou < alcanceMover)
							andou = alcanceMover - andou;
					}
				}
			}
			else if (perseguindoJog2) {
				if (distanciaJog2 < 0) {
					if (direcao == 1) {
						direcao = -1;
						if (andou < alcanceMover)
							andou = alcanceMover - andou;
					}
				}
				else {
					if (direcao == -1) {
						direcao = 1;
						if (andou < alcanceMover)
							andou = alcanceMover - andou;
					}
				}
			}
		}
		int Vampiro::getVidas() {
			return this->vidas;
		}
	}
}
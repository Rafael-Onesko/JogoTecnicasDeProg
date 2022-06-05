#include "Dragao.h"
Dragao::Dragao(Jogador* jog1, Jogador* jog2) : Inimigo(150.f, 100.f, 80.f, dragao, jog1, jog2) {
	vidas = 500;
	alcanceMover = 3*tamX;
	alcanceAtacar = 2 * tamX;
	velocidadeY = 0;
	ataca = false;
	atacando = false;
	fugindo = false;
	tempoAtaque = 2.f;
	tempoAtacando = 0.0f;
}
Dragao::~Dragao() {
	bolaDeFogo = nullptr;
}
Dragao::Dragao() :Inimigo() {

}


void Dragao::receberDano() {
	fugindo = true;
	vidas--;
	if (vidas < 0) {
		vivo = false;
	}
}


void Dragao::colidir(ID IdOutro, float colisaoX, float colisaoY) {
    bool colidX = false;
    if (colisaoY > colisaoX)
        colidX = true;


    if (colidX) {
        if (direcao > 0)
            this->setPosX(posX - colisaoX);
        else
            this->setPosX(posX + colisaoX);
        velocidadeX = 0;
        if (andou < alcanceMover)
            andou = alcanceMover - andou;
        direcao = -direcao;
        if (IdOutro == ID::jogador1)
            jogador1->receberDano();
        else if (IdOutro == ID::jogador2)
            jogador2->receberDano();
    }
    else {
        if (IdOutro == ID::jogador1) {
			if (!jogador1->getDirecaoCima()) {
				this->receberDano();
				fugindo = true;
			}
			else
				jogador1->receberDano();
        }
        else if (IdOutro == ID::jogador2) {
			if (!jogador2->getDirecaoCima()) {
				this->receberDano();
				fugindo = true;
			}
			else
				jogador2->receberDano();
        }
        else {
            this->setPosY(posY - colisaoY);
        }
        velocidadeY = 0;
        noChao = true;
    }
}


void Dragao::ajustarDeslocamento(float dt) {
	if (andou < alcanceMover) {
		velocidadeX = velPadrao * dt * direcao;
		if (fugindo)
			velocidadeX = velocidadeX * 3;
		andou += fabs(velocidadeX);
	}
	else {
		andou = 0;
		direcao = -direcao;
	}
}


void Dragao::executar(float dt) {
	procuraJogador();
	if(atacando)
		corpo->setFillColor(sf::Color::Magenta);
	if((ataca) && !(fugindo))
		atacar(dt);
	if(!atacando)
		corpo->setFillColor(sf::Color::White);
	ajustarDeslocamento(dt);
	mover();
}


void Dragao::atacar(float dt) {
	if (!atacando) {
		atacando = true;
		tempoAtacando = 0;
		tacarFogo();
	}
	else if (tempoAtacando < tempoAtaque) {
		tempoAtacando += dt;
	}
	else {
		atacando = false;
		tempoAtacando = 0;
	}
}


void Dragao::tacarFogo() {

}


void Dragao::procuraJogador() {
	distanciaJog1X = jogador1->getCentroX() - this->getCentroX();
	distanciaJog2X = FLT_MAX;
	distanciaJog1Y = jogador1->getCentroY() - this->getCentroY();
	distanciaJog2Y = FLT_MAX;

	if (jogador2) {
		distanciaJog2X = jogador2->getCentroX() - this->getCentroX();
		distanciaJog2Y = jogador2->getCentroY() - this->getCentroY();
	}
	if (fugindo) {
		if (fabs(distanciaJog1X) > 2 * tamX && fabs(distanciaJog2X) > 2 * tamX)
			fugindo = false;
	}
	else {
		if ((fabs(distanciaJog1X) < tamX && distanciaJog1Y < 0)||(fabs(distanciaJog2X) < tamX && distanciaJog2Y < 0)) {
			fugindo = true;
			ataca = false;
		}
		else if ((fabs(distanciaJog1X) <= alcanceAtacar && distanciaJog1Y > 0)|| (fabs(distanciaJog2X) <= alcanceAtacar && distanciaJog2Y > 0)){
			ataca = true;
		}
		else {
			ataca = false;
		}
	}
}
bool Dragao::getAtacando() {
	return this->atacando;
}
float Dragao::getTempoAtaque() {
	return this->tempoAtaque;
}
int Dragao::getVidas() {
	return this->vidas;
}
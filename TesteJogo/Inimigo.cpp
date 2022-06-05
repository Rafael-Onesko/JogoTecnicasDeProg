#include "Inimigo.h"
Inimigo::Inimigo(): Personagem() {
	vivo = true;
	direcao = 1;
	andou = 0;
}  
Inimigo::Inimigo(float tX, float tY, float vel, ID id, Jogador* jog1, Jogador* jog2) :Personagem(id, tX, tY, vel) {
	alcanceMover = 2 * tX;
	vivo = true;
	direcao = 1;
	andou = 0;
    this->jogador1 = jog1;
    this->jogador2 = jog2;
}

Inimigo::~Inimigo() {

    this->jogador1 = nullptr;
    this->jogador2 = nullptr;
}
void Inimigo::setJogador2(Jogador* jog2) {
	this->jogador2 = jog2;
}
void Inimigo::ajustarDeslocamento(float dt) {
    posXant = posX;
    posYant = posY;
    if (andou < alcanceMover) {
        velocidadeX = velPadrao * dt * direcao;
        this->setPosX(posX + velocidadeX);
        andou += velPadrao * dt;
    }
    else {
        andou = 0;
        direcao = -direcao;
    }
    if (direcao > 0)
        direcaoDireita = true;
    else
        direcaoDireita = false;
    if(!noChao)
        velocidadeY = velocidadeY + GRAVIDADE * dt * dt;
    this->setPosY(posY + velocidadeY);
    noChao = false;
}

void Inimigo::colidir(ID IdOutro, float colisaoX, float colisaoY) {

    bool colidX = false;
    if (colisaoY > colisaoX)
        colidX = true;


    if (colidX) {
        if (direcao > 0)
            this->setPosX(posX - colisaoX);
        else
            this->setPosX(posX + colisaoX);
        velocidadeX = 0;
       if(andou < alcanceMover)
            andou = alcanceMover - andou;
        direcao = -direcao;
        if (IdOutro == ID::jogador1)
            jogador1->receberDano();
        else if (IdOutro == ID::jogador2)
            jogador2->receberDano();
    }
    else {
        if (IdOutro == ID::jogador1) {
            if (!jogador1->getDirecaoCima())
                this->receberDano();
        }
        else if (IdOutro == ID::jogador2) {
            if (!jogador2->getDirecaoCima())
                this->receberDano();
        }
        else {
            this->setPosY(posY - colisaoY);
        }
        velocidadeY = 0;
        noChao = true;
    }
}
#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include <stdio.h>
Jogador::Jogador(float tX, float tY, float vel) :Personagem(jogador1, tX, tY, vel) {
posXant = 0;
posYant = 0;
vidas = 100;
naAgua = false;
}
Jogador::Jogador():Personagem(){
vidas = 0;
}
Jogador::~Jogador(){
     
}
void Jogador::ajustarDeslocamento(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocidadeX = velPadrao*dt;
        direcaoDireita = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocidadeX = -velPadrao * dt;
        direcaoDireita = false;
    }
    else
        velocidadeX = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        //printf("%f\n", dt);
        if (dt > 0.009f)
            dt = 0.009f;
        if (dt < 0.007f)
            dt = 0.007f;
        if (noChao) {
            velocidadeY = -velPadrao * 2.7f * dt;
            noChao = false;
        }
        else if (naAgua) {
            velocidadeY = -velPadrao * 0.7f * dt;
            noChao = false;
        }
    }
    if (!noChao)
        velocidadeY += (float)GRAVIDADE * dt * dt;
    else
        velocidadeY = 0;
    if (posY < posYant)
        direcaoCima = true;
    else
        direcaoCima = false;
    if (naAgua) {
        velocidadeX = velocidadeX / 10.f;
        velocidadeY = velocidadeY / 1.2f;
    }
    noChao = false;
    naAgua = false;
}
void Jogador::colidir(ID IdOutro, float colisaoX, float colisaoY) {
         
    bool colidX = false;
    if (posYant != posY && posXant == posX) {
        colidX = false;
    }
    else if (posYant == posY && posXant != posX){
        colidX = true;
    }
    else if (posYant == posY && posXant == posX){
        colidX   = true;
    }
    else if (colisaoX > colisaoY){
            colidX = false;
}
    else
        colidX = true;
    if (IdOutro != agua){
        if (IdOutro == espinho) {
            this->receberDano();
        }
        else if (IdOutro == bolaDeFogo) 
                this->receberDano(25);
        if (colidX) {
            if (posX != posXant) {
                if (direcaoDireita)
                    this->setPosX(posX - colisaoX);
                else
                    this->setPosX(posX + colisaoX);
            //   posXant = posX;
            }
            velocidadeX = 0;
        }
        else {
            if (!direcaoCima) {
                this->setPosY(posY - colisaoY);
                noChao = true;
            }

            else {
                this->setPosY(posY + colisaoY);
            }
            velocidadeY = 0;
            posYant = posY;
        }
    }
    else if (IdOutro == ID::agua) {
        naAgua = true;
    }
}

void Jogador::receberDano(int dano) {
    vidas -= dano;
    if (vidas <= 0) {
        vivo = false;
    }
}
int Jogador::getVidas() {
    return vidas;
}
void Jogador::executar(float dt) {
    ajustarDeslocamento(dt);
    mover();
    gerenciadorGrafico->ajustarCamera(corpo);
}
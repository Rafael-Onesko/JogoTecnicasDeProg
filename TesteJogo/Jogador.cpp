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
             if (noChao) {
                 velocidadeY = -velPadrao * 4.7f * 0.002f;
                 noChao = false;
             }
             else if (naAgua) {
                 velocidadeY = -velPadrao * 1.7f * 0.002f;
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
             if (IdOutro == ID::vampiro || IdOutro == ID::goblin)
                 printf("1  %d  %f %f %f\n", noChao, velocidadeY, posY, posYant);
         }
         else if (posYant == posY && posXant != posX){
             colidX = true;
             if (IdOutro == ID::vampiro || IdOutro == ID::goblin)
                 printf("2\n");
         }
         else if (posYant == posY && posXant == posX){
             colidX   = true;
             if (IdOutro == ID::vampiro || IdOutro == ID::goblin)
                 printf("3\n");
         }
         else if (colisaoX > colisaoY){
                 colidX = false;
             if (IdOutro == ID::vampiro || IdOutro == ID::goblin)
                 printf("4\n");
        }
         else
             colidX = true;
         if (IdOutro != agua && IdOutro != bolaDeFogo){
             if (IdOutro == espinho)
                 this->receberDano();
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

     void Jogador::receberDano() {
         vidas -= 1;
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
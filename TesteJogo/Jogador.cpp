#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#define GRAVIDADE 0.009
    Jogador::Jogador(float tX, float tY, float vel) :Personagem(1, tX, tY, vel) {

    }
    Jogador::Jogador():Personagem(){
    }
     Jogador::~Jogador(){
     }
     void Jogador::move() {
         posXant = posX;
         posYant = posY;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
             direcaoDireita = true;
             velocidadeX = velPadrao;
         }
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
             direcaoDireita = false;
             velocidadeX = -velPadrao;
         }
         else
             velocidadeX = 0;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

             velocidadeY = -velPadrao*2;
         }
         else if (posY > 250) {
             velocidadeY = 0;
         }
         velocidadeY += (float)GRAVIDADE;
         if (posY > 250) {
             this->setPosY(250.f);
         }
         if (velocidadeY < 0)
             direcaoCima = true;
         else
             direcaoCima = false;
         this->setPosX(posX + velocidadeX);
         this->setPosY(posY + velocidadeY);
     }
     void Jogador::colidir(int IdOutro, float colisaoX, float colisaoY) {
         bool colidX = false, colidY = false;
         if (posYant != posY)
             colidY = true;
         else 
             colidX = true;
         /*if (posYant != posY && posXant == posX)
             colidY = true;
         else if (colisaoY > colisaoX)
             colidX = true;
         else
             colidY = true;*/
         switch (IdOutro) {
         case 2://Obstaculo
             if (colidX) {
                 if (direcaoDireita)
                     this->setPosX(posX - colisaoX);
                 else
                     this->setPosX(posX + colisaoX);
             }
             else {
                 if (!direcaoCima)
                     this->setPosY(posY - colisaoY);
                 else
                     this->setPosY(posY + colisaoY);
                 velocidadeY = 0;
             }
             break;
         case 3://Inimigo
             if (colidX) {
                 if (direcaoDireita)
                     this->setPosX(posX - colisaoX);
                 else
                     this->setPosX(posX + colisaoX);
             }
             else {
                 if (!direcaoCima)
                     this->setPosY(posY - colisaoY);
                 else
                     this->setPosY(posY + colisaoY);
                 velocidadeY = 0;
             }
             break;
         default:
             break;
         }
     }
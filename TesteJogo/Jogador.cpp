#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#define GRAVIDADE 0.009
    Jogador::Jogador(float tX, float tY, float vel) :Personagem(1, tX, tY, vel) {
        posXant = 0;
        posYant = 0;
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
         else// if (velocidadeY == 0)
             velocidadeX = 0;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
             if(velocidadeY == 0)
                velocidadeY = -velPadrao*3.7f;
         }
         velocidadeY += (float)GRAVIDADE;
         if (velocidadeY < 0)
             direcaoCima = true;
         else
             direcaoCima = false;
         this->setPosX(posX + velocidadeX);
         this->setPosY(posY + velocidadeY);
         if (posX < 0)
             setPosX(0.f);

         if (posY < 0) {
             setPosY(0.f);
             velocidadeY = 0;
         }
     }
     void Jogador::colidir(int IdOutro, float colisaoX, float colisaoY) {
         bool colidX = false, colidY = false;
         /*if (posYant != posY)
             colidY = true;
         else 
             colidX = true;*/
         if (posYant != posY && posXant == posX)
             colidY = true;
         else if (posYant == posY && posXant != posX)
             colidX = true;
         else if (colisaoX > colisaoY)
             colidY = true;
          else
            colidX = true;
         switch (IdOutro) {
         case 2://Obstaculo
             if (colidX) {
                 if (direcaoDireita)
                     this->setPosX(posX - colisaoX);
                 else
                     this->setPosX(posX + colisaoX);
                 velocidadeX = 0;
             }
             else {
                 if (!direcaoCima) {
                     this->setPosY(posY - colisaoY);
                     velocidadeY = 0;
                 }
                 else
                     this->setPosY(posY + colisaoY);
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
                 if (!direcaoCima) {
                     this->setPosY(posY - colisaoY);
                     velocidadeY = 0;
                 }
                 else
                     this->setPosY(posY + colisaoY);
             }
             break;
         default:
             break;
         }
     }
#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
    Jogador::Jogador(float tX, float tY, float vel) :Personagem(1, tX, tY, vel) {

    }
    Jogador::Jogador():Personagem(){
    }
     Jogador::~Jogador(){
     }
     void Jogador::move() {
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
             direcaoDireita = true;
             this->setPosX(posX + velocidadeX);
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
             direcaoDireita = false;
             this->setPosX(posX - velocidadeX);
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
             direcaoCima = true;
             this->setPosY(posY - velocidadeY);
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
             direcaoCima = false;
             this->setPosY(posY + velocidadeY);
         }
     }
     void Jogador::colidir(int IdOutro, float colisaoX, float colisaoY) {
         bool colidX = false, colidY = false;
         if (colisaoY > colisaoX)
             colidY = true;
         else
             colidX = true;
         switch (IdOutro) {
         case 2://Obstaculo
             if (colisaoX) {
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
             }
             break;
         default:
             break;
         }
     }
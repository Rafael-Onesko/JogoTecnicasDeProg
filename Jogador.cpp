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
             posX += velocidade;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
             posX -= velocidade;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
             posY -= velocidade;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
             posY += velocidade;
         }
     }
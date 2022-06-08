#pragma once
#include <SFML/Graphics.hpp>
#include "Personagem.h"
class Jogador : public Personagem {
private:
    int vidas;
    bool naAgua;
    sf::Keyboard::Key direita;
    sf::Keyboard::Key esquerda;
    sf::Keyboard::Key cima;
public:
    Jogador(float pX, float pY, ID id, int vidas);
    Jogador();
    ~Jogador();
    void colidir(ID IdOutro, float colisaoX, float colisaoY);
    void receberDano(int dano = 1);
    int getVidas();
    void executar(float dt);
    void ajustarDeslocamento(float dt);
};
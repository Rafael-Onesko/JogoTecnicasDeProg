#pragma once
#include <SFML/Graphics.hpp>
#include "Personagem.h"
class Jogador : public Personagem {
private:
    int vidas;
    bool naAgua;
public:
    Jogador(float tX, float tY, float vel);
    Jogador();
    ~Jogador();
    void colidir(ID IdOutro, float colisaoX, float colisaoY);
    void receberDano(int dano = 1);
    int getVidas();
    void executar(float dt);
    void ajustarDeslocamento(float dt);
};
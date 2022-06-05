#pragma once
#include <SFML/Graphics.hpp>
#include "Personagem.h"
class Jogador : public Personagem {
private:
    int vidas;
public:
    Jogador(float tX, float tY, float vel);
    Jogador();
    ~Jogador();
    void colidir(ID IdOutro, float colisaoX, float colisaoY);
    void receberDano();
    int getVidas();
    void executar(float dt);
    void ajustarDeslocamento(float dt);
};
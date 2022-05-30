#pragma once
#include <SFML/Graphics.hpp>
#include "Personagem.h"
class Jogador : public Personagem {
private:
public:
    Jogador(float tX, float tY, float vel);
    Jogador();
    ~Jogador();
    void move();
    void colidir(int IdOutro, float colisaoX, float colisaoY);
};
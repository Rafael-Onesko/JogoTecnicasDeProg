#pragma once
#include "Personagem.h"
#include "Barra_Vida.h"
class Jogador : public Personagem {
private:
    int vidas;
    bool naAgua;
    Barra_Vida* barraVida;
    sf::Keyboard::Key direita;
    sf::Keyboard::Key esquerda;
    sf::Keyboard::Key cima;
public:
    Jogador(Gerenciador_Grafico* gerenciadorGrafico, float pX, float pY, ID id, int vidas = 100);
    Jogador();
    ~Jogador();
    void colidir(ID IdOutro, float colisaoX, float colisaoY);
    void receberDano(int dano = 1);
    int getVidas();
    void executar(float dt);
    void ajustarDeslocamento(float dt);
    virtual void imprimir_se();
};
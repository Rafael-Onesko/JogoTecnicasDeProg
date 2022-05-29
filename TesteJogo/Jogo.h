#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
class Jogo {
private:
    Jogador* player1;
    Gerenciador_Grafico* gerenciadorGrafico;
public:
    Jogo();
    ~Jogo();
    void executar();
};
#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Fase.h"
class Jogo {
private:
    Gerenciador_Grafico* gerenciadorGrafico;
    Fase* faseTeste;
public:
    Jogo();
    ~Jogo();
    void executar();
};
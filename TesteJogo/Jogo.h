#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Colisoes.h"
#include "Fase_Castelo.h"
#include "Fase_Floresta.h"
class Jogo {
private:
    static Gerenciador_Grafico* gerenciadorGrafico;
    Fase_Floresta* faseFloresta;
    Fase_Castelo* faseCastelo;
    Fase* faseAtual;
    bool fasePrimeira;
public:
    Jogo();
    ~Jogo();
    void executar();
    static Gerenciador_Grafico* getGerenciadorGrafico();
};
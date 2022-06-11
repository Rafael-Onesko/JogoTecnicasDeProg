#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Colisoes.h"
#include "Fase_Castelo.h"
#include "Fase_Floresta.h"
class Jogo {
private:
    static Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
    Fases::Fase_Floresta* faseFloresta;
    Fases::Fase_Castelo* faseCastelo;
    Fases::Fase* faseAtual;
    bool fasePrimeira;
public:
    Jogo();
    ~Jogo();
    void executar();
    static Gerenciadores::Gerenciador_Grafico* getGerenciadorGrafico();
};
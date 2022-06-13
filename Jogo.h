#pragma once
#include "Gerenciador_Colisoes.h"
#include "Menu.h"
#include "Fase_Castelo.h"
#include "Fase_Floresta.h"
class Jogo {
private:
    static Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
    Fases::Fase_Floresta* faseFloresta;
    Fases::Fase_Castelo* faseCastelo;
    Fases::Fase* faseAtual;
    Menu* menu;
    bool fasePrimeira;
    bool doisJogadores;
    bool inicializado;
public:
    Jogo();
    ~Jogo();
    void executar();
    void recebeMenu();
    void inicializaFases();
    static Gerenciadores::Gerenciador_Grafico* getGerenciadorGrafico();
};
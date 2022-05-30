#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "inimigo.h"
#include "ListaEntidades.h"
class Jogo {
private:
    Jogador* player1;
    Inimigo* enemy1;
    Gerenciador_Grafico* gerenciadorGrafico;
    Gerenciador_Colisoes* gerenciadorColisoes;
    ListaEntidades* entidades;
public:
    Jogo();
    ~Jogo();
    void executar();
};